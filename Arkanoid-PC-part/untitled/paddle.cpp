#include <iostream>
#include "paddle.h"

/*!
    \file
    \brief This file is responsible for creating a paddle.

    It contains methods that difine how the paddle should move.
*/

/*!
    \brief Constructor for Paddle.

    It loads an image and creates a rectangle in size of image.
*/
Paddle::Paddle() {

    dx = 0;
    dy = 0;
    image.load("paddle.png");

    rect = image.rect();
    resetState();
}

/*!
    \brief Destructor for Paddle.
*/
Paddle::~Paddle() {

    std::cout << ("Paddle deleted") << std::endl;
}

/*!
    \brief Sets value of "dx".

    "dx" is responsible for direction of movement on X axis.
    \param[in] x direction and speed of movement
*/
void Paddle::setDx(int x) {
    dx = x;
}

/*!
    \brief Sets value of "dy".

    "dy" is responsible for direction of movement on Y axis.
    \param[in] y direction and speed of movement
*/

void Paddle::setDy(int y) {
    dy = y;
}
/*!
    \brief This method allows us to move paddle in different directions.

    Also it sets borders for paddle, in which it can move.
*/
void Paddle::move() {

    int x = rect.x() + dx;
    int y = rect.y() + dy;

    if (x < LEFT_BOUND) {
        x = LEFT_BOUND;
    } else if (x > RIGHT_BOUND) {
        x = RIGHT_BOUND;
    }

    if (y < UPPER_BOUND) {
        y = UPPER_BOUND;
    } else if (y > LOWER_BOUND) {
        y = LOWER_BOUND;
    }

    rect.moveTo(x, y);
}

/*!
    \brief This method returns paddle to its original position.
*/
void Paddle::resetState() {

    rect.moveTo(INITIAL_X, INITIAL_Y);
}

/*!
    \brief This method returns value of rect.
    \param[out] rect
*/

QRect Paddle::getRect() {

    return rect;
}

/*!
    \brief This method returns value of image.
    \param[out] image
*/

QImage & Paddle::getImage() {

    return image;
}
