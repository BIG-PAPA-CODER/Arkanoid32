#pragma once
/*!
    \file
    \brief Header file for paddle.cpp.

*/
#include <QImage>
#include <QRect>

class Paddle {

public:
    Paddle();
    ~Paddle();
    int dx;
    int dy;

public:
    void resetState();
    void move();
    void setDx(int);
    void setDy(int);
    QRect getRect();
    QImage & getImage();

private:
    QImage image;
    QRect rect;
    //int dx;
    static const int INITIAL_X = 200;
    static const int INITIAL_Y = 360;
    static const int UPPER_BOUND = 300;   // Upper limit for y-axis
    static const int LOWER_BOUND = 360;  // Lower limit for y-axis
    static const int LEFT_BOUND = 0;   // Left limit for x-axis
    static const int RIGHT_BOUND = 256;  // Right limit for x-axis
};
