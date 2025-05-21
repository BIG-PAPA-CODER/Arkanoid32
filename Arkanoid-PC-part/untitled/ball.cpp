#include <iostream>
#include "ball.h"

/*!
    \file
    \brief This file is responsible for creating a ball.

    It contains methods that difine how the ball should move.
*/

/*!
    \brief Construktor for "Ball" object.

    It loads image of ball and creates rectangle in size of it. Also it implements direction of movement here:
    \code
    xdir = 1;
    ydir = -1;
    \endcode
    that means that ball is going to move up and right.
*/
Ball::Ball() {

    xdir = 1;
    ydir = -1;

    image.load("ball.png");

    rect = image.rect();
    resetState();
}

/*!
    \brief Destruktor for "Ball" object.
*/
Ball::~Ball() {

    std::cout << ("Ball deleted") << std::endl;
}

/*!
    \brief This method tells how the ball should move in game area.

    If it touches a left, right or top wall it will bounce of them. If ball touches low border then it not going to bounce back.
*/
void Ball::autoMove() {

    rect.translate(xdir, ydir);

    if (rect.left() == 0) {
        xdir = 1;
    }

    if (rect.right() == RIGHT_EDGE) {
        xdir = -1;
    }

    if (rect.top() == 0) {
        ydir = 1;
    }
}

/*!
    \brief This method returns ball to its original position.
*/
void Ball::resetState() {

    rect.moveTo(INITIAL_X, INITIAL_Y);
}

/*!
    \brief This method sets "X" direction variable.
    \param[in] x direction of movement on X axis
*/
void Ball::setXDir(int x) {

    xdir = x;
}

/*!
    \brief This method sets "Y" direction variable.
    \param[in] y direction of movement on Y axis
*/
void Ball::setYDir(int y) {

    ydir = y;
}

/*!
    \brief This method returns value of xdir.
    \param[out] xdir direction of movement on X axis
*/

int Ball::getXDir() {

    return xdir;
}

/*!
    \brief This method returns value of ydir.
    \param[out] ydir direction of movement on Y axis
*/

int Ball::getYDir() {

    return ydir;
}

/*!
    \brief This method returns value of rect.
    \param[out] rect
*/

QRect Ball::getRect() {

    return rect;
}

/*!
    \brief This method returns value of image.
    \param[out] image
*/

QImage & Ball::getImage() {

    return image;
}
