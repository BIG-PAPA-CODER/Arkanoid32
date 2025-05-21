#include <iostream>
#include "brick.h"
/*!
    \file
    \brief This file is responsible for creating bricks.

    It contains methods that help to create brics and destroy them.
*/

/*!
    \brief Constructor for "Brick" object.

    It loads image of brick and creates rectangle in size of it, sets flag variable "destroyed" to false, what means that it wasn't destroyed yet.
    \param[in] x coordinate of brick on X axis
    \param[in] y coordinate of brick on Y axis
*/
Brick::Brick(int x, int y) {

    image.load("brickie_blue.png");
    destroyed = false;
    rect = image.rect();
    rect.translate(x, y);
}
/*!
    \brief Destructor for "Brick" object.
*/
Brick::~Brick() {

    std::cout << ("Brick deleted") << std::endl;
}

/*!
    \brief This method returns value of rect.
    \param[out] rect
*/

QRect Brick::getRect() {

    return rect;
}

/*!
    \brief This method sets value of rect.
    \param[in] rct
*/

void Brick::setRect(QRect rct) {

    rect = rct;
}

/*!
    \brief This method returns value of image.
    \param[out] image
*/

QImage & Brick::getImage() {

    return image;
}

/*!
    \brief This method cheks if "Brick" was destroyed.
*/
bool Brick::isDestroyed() {

    return destroyed;
}

/*!
    \brief This method sets value of destroyed.
    \param[in] destr
*/

void Brick::setDestroyed(bool destr) {

    destroyed = destr;
}
