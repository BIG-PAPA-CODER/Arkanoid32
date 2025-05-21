#pragma once

#include <QWidget>
#include <QKeyEvent>
#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include <QSerialPort>
#include <QTimer>


class Breakout_M : public QWidget {

public:
    Breakout_M(QWidget *parent = 0);
    ~Breakout_M();
    //int x_acc;
    //, y_acc, z_acc, sumdata;

protected:
    void readFromPort();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *);
    void finishGame(QPainter *, QString);
    void moveObjects();

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();

private slots:
    void updateXAcc();  // Slot for updating x_acc

private:
    QSerialPort *device;
    int x;
    int timerId;
    static const int N_OF_BRICKS = 30;
    static const int DELAY = 10;
    static const int BOTTOM_EDGE = 400;
    Ball *ball;
    Paddle *paddle;
    Brick *bricks[N_OF_BRICKS];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    //int timerId;
    QTimer *updateTimer;  // Timer for updating x_acc
    unsigned short int ComputeCRC16(const char* pData, int Length, unsigned int Poly, unsigned short int InitVal)
    {
        short int i;
        unsigned short int ResCRC = InitVal;

        while (--Length >= 0) {
            ResCRC ^= *pData++ << 8;
            for (short int i=0; i < 8; ++i)
                ResCRC = ResCRC & 0x8000 ? (ResCRC << 1) ^ Poly : ResCRC << 1;
        }
        return ResCRC & 0xFFFF;
    }
};
