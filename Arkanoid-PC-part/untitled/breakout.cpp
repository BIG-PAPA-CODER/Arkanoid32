#include <QPainter>
#include <QApplication>
#include <QDebug>
#include <QList>
#include <QSerialPortInfo>
#include "breakout.h"
#include "SharedData.h"
//#include "mainwindow.h"

#define CRC16_INIT        0
#define CRC16_POLYNOMIAL  0x8005

/*!
    \file
    \brief This file is responsible for game logic.

*/

/*!
    \brief Constructor for "Breakout" object. It contains main game logic.

    It sets game-state variables and creates objects of game, such as Paddle, Ball and wall of Bricks. Also it includes inicialisation of timer, which checks x_acc value every 100ms.
*/
Breakout::Breakout(QWidget *parent)
    : QWidget(parent), updateTimer(new QTimer(this)) {

    this->device = new QSerialPort(this);

    x = 0;
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    ball = new Ball();
    paddle = new Paddle();

    int k = 0;

    for (int i=0; i<5; i++) {
        for (int j=0; j<6; j++) {
            bricks[k] = new Brick(j*40+30, i*10+50);
            k++;
        }
    }

    connect(updateTimer, &QTimer::timeout, this, &Breakout::updateXAcc);
    updateTimer->start(100);  // Check x_acc value every 100 ms
}

/*!
    \brief Destructor for "Breakout" object.
*/
Breakout::~Breakout() {

    delete ball;
    delete paddle;

    for (int i=0; i<N_OF_BRICKS; i++) {
        delete bricks[i];
    }
}

/*!
    \brief This method draws game state messeges depending on its state.
    \param[in] e

*/
void Breakout::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    QPainter painter(this);

    if (gameOver) {

        finishGame(&painter, "Game lost");

    } else if(gameWon) {

        finishGame(&painter, "Victory");
    }
    else {

        drawObjects(&painter);
    }
}

/*!
    \brief This method texts out a message when game is finished.
    \param[in] painter object of QPainter class
    \param[in] message string text
*/
void Breakout::finishGame(QPainter *painter, QString message) {

    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);
}

/*!
    \brief This method draws all the objects in a game window.
    \param[in] painter object of QPainter class
*/
void Breakout::drawObjects(QPainter *painter) {

    painter->drawImage(ball->getRect(), ball->getImage());
    painter->drawImage(paddle->getRect(), paddle->getImage());

    for (int i=0; i<N_OF_BRICKS; i++) {
        if (!bricks[i]->isDestroyed()) {
            painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
        }
    }
}

/*!
    \brief This method redraw objects after moving them and cheking for collisions.
    \param[in] e
*/
void Breakout::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    moveObjects();
    checkCollision();
    repaint();
}

/*!
    \brief This method is responsible for movement of objects (paddle and ball).
*/
void Breakout::moveObjects() {

    ball->autoMove();
    paddle->move();
}

/*!
    \brief This method checks if key was released and changes dx to 0.
    \param[in] e
*/
void Breakout::keyReleaseEvent(QKeyEvent *e) {

    int dx = 0;

    switch (e->key()) {

    // case Qt::Key_M:
    //     qDebug() << "--->" << SharedData::getInstance().x_acc;
    //     if(SharedData::getInstance().x_acc < -4000){
    //         dx = -1;
    //         paddle->setDx(dx);
    //     } else if(SharedData::getInstance().x_acc > 4000){
    //         dx = 1;
    //         paddle->setDx(dx);
    //     } else {
    //         dx = 0;
    //         paddle->setDx(dx);
    //     }

    //     break;

    case Qt::Key_Left:
        dx = 0;
        paddle->setDx(dx);
        break;

    case Qt::Key_Right:
        dx = 0;
        paddle->setDx(dx);
        break;
    }
}

/*!
    \brief This method allows to update x_acc and y_acc values and direct them to the game.
*/

void Breakout::updateXAcc() {
    int dx = 0;
    int dy = 0; // Add vertical movement

    //qDebug() << "--->" << SharedData::getInstance().x_acc << SharedData::getInstance().y_acc;
    if (SharedData::getInstance().x_acc < -4000 && SharedData::getInstance().x_acc > -8000) {
        dx = -1;
    } else if (SharedData::getInstance().x_acc < -8000) {
        dx = -2;
    } else if (SharedData::getInstance().x_acc > 4000 && SharedData::getInstance().x_acc < 8000) {
        dx = 1;
    } else if (SharedData::getInstance().x_acc > 8000) {
        dx = 2;
    } else {
        dx = 0;
    }

    if (SharedData::getInstance().y_acc < -4000 && SharedData::getInstance().x_acc > -8000) {
        dy = -1;
    } else if (SharedData::getInstance().y_acc < -8000) {
        dx = -2;
    } else if (SharedData::getInstance().y_acc > 4000 && SharedData::getInstance().x_acc < 8000) {
        dy = 1;
    } else if (SharedData::getInstance().y_acc > 8000) {
        dx = 2;
    } else {
        dy = 0;
    }

    paddle->setDx(dx);
    paddle->setDy(dy);
}

/*!
    \brief This method checks what key was pressed and realizes several functions.

    For example we can control paddle movement with left and right arrows, start the game with space, pause with p and exit with escape.
    \param[in] e
*/
void Breakout::keyPressEvent(QKeyEvent *e) {

    int dx = 0;

    switch (e->key()) {
    // case Qt::Key_M:
    //     //while(1){
    //         qDebug() << "--->" << SharedData::getInstance().x_acc;
    //         if(SharedData::getInstance().x_acc < -4000){
    //             dx = -1;
    //             paddle->setDx(dx);
    //         } else if(SharedData::getInstance().x_acc > 4000){
    //             dx = 1;
    //             paddle->setDx(dx);
    //         } else {
    //             dx = 0;
    //             paddle->setDx(dx);
    //         }
    //         //delay(200);
    //     //}
    //     break;

    case Qt::Key_Left:

        dx = -1;
        paddle->setDx(dx);

        break;

    case Qt::Key_Right:

        dx = 1;
        paddle->setDx(dx);
        break;

    case Qt::Key_P:

        pauseGame();
        break;

    case Qt::Key_Space:

        startGame();
        break;

    case Qt::Key_Escape:

        qApp->exit();
        break;

    default:
        QWidget::keyPressEvent(e);
    }
}

/*!
    \brief This method is responsible for starting the game.
*/
void Breakout::startGame() {

    if (!gameStarted) {
        ball->resetState();
        paddle->resetState();

        for (int i=0; i<N_OF_BRICKS; i++) {
            bricks[i]->setDestroyed(false);
        }

        gameOver = false;
        gameWon = false;
        gameStarted = true;
        timerId = startTimer(DELAY);
    }
}

/*!
    \brief This method is responsible for pausing the game.
*/
void Breakout::pauseGame() {

    if (paused) {

        timerId = startTimer(DELAY);
        paused = false;
    } else {

        paused = true;
        killTimer(timerId);
    }
}

/*!
    \brief This method is responsible for game over.
*/
void Breakout::stopGame() {

    killTimer(timerId);
    gameOver = true;
    gameStarted = false;
}

/*!
    \brief This method is responsible for stopping the game if all bricks were destroyed.
*/
void Breakout::victory() {

    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
}

/*!
    \brief This method checks if collision had happened.

    It defines interraction between ball and bricks with paddle. Also it checks for gameover situations, such as if ball fell or all of the bricks were destroyed.
*/
void Breakout::checkCollision() {

    if (ball->getRect().bottom() > BOTTOM_EDGE) {
        stopGame();
    }

    for (int i=0, j=0; i<N_OF_BRICKS; i++) {

        if (bricks[i]->isDestroyed()) {
            j++;
        }

        if (j == N_OF_BRICKS) {
            victory();
        }
    }

    if ((ball->getRect()).intersects(paddle->getRect())) {

        int paddleLPos = paddle->getRect().left();
        int ballLPos = ball->getRect().left();

        int first = paddleLPos + 8;
        int second = paddleLPos + 16;
        int third = paddleLPos + 24;
        int fourth = paddleLPos + 32;

        if (ballLPos < first) {
            ball->setXDir(-1);
            ball->setYDir(-1);
        }

        if (ballLPos >= first && ballLPos < second) {
            ball->setXDir(-1);
            ball->setYDir(-1*ball->getYDir());
        }

        if (ballLPos >= second && ballLPos < third) {
            ball->setXDir(0);
            ball->setYDir(-1);
        }

        if (ballLPos >= third && ballLPos < fourth) {
            ball->setXDir(1);
            ball->setYDir(-1*ball->getYDir());
        }

        if (ballLPos > fourth) {
            ball->setXDir(1);
            ball->setYDir(-1);
        }
    }

    for (int i=0; i<N_OF_BRICKS; i++) {

        if ((ball->getRect()).intersects(bricks[i]->getRect())) {

            int ballLeft = ball->getRect().left();
            int ballHeight = ball->getRect().height();
            int ballWidth = ball->getRect().width();
            int ballTop = ball->getRect().top();

            QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
            QPoint pointLeft(ballLeft - 1, ballTop);
            QPoint pointTop(ballLeft, ballTop -1);
            QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

            if (!bricks[i]->isDestroyed()) {
                if(bricks[i]->getRect().contains(pointRight)) {
                    ball->setXDir(-1);
                }

                else if(bricks[i]->getRect().contains(pointLeft)) {
                    ball->setXDir(1);
                }

                if(bricks[i]->getRect().contains(pointTop)) {
                    ball->setYDir(1);
                }

                else if(bricks[i]->getRect().contains(pointBottom)) {
                    ball->setYDir(-1);
                }

                bricks[i]->setDestroyed(true);
            }
        }
    }
}
