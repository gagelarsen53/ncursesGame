/*
 * File:   Ball.cpp
 * Author: mikewright
 *
 * Created on August 14, 2014, 9:04 AM
 */

#include "Ball.h"
#include <stdlib.h>
#include <ncurses.h>

Ball::Ball() { }
Ball::Ball(const Ball& orig) { }
Ball::~Ball() { }

int Ball::GetX() { return _x; }
int Ball::GetY() { return _y; }
int Ball::GetUpperBound() { return _upperBound; }
int Ball::GetLowerBound() { return _lowerBound; }
int Ball::GetXDir() { return dir_x; }
int Ball::GetYDir() { return dir_y; }

void Ball::Render() {
    mvaddstr(GetY(), GetX(), " ");
    Move(_x, _y);
    mvaddstr(GetY(), GetX(), "0");
    usleep(100000);
}

void Ball::Init(int x, int y, int upperBound, int lowerBound, int userBound, int cpuBound) {
    _x = x;
    _y = y;
    _upperBound = upperBound;
    _lowerBound = lowerBound;
    _userBound = userBound;
    _cpuBound = cpuBound;
    dir_updown = 1;
    dir_leftright = 1;
    dir_x = 1;
    dir_y = 1;
}

void Ball::Move(float x, float y) {
    if (isnan(x)) {
        x = rand() % 2 + 1;
        if (rand() % 2 == 0) {
            x = x * -1;
        }
    }
    if (isnan(y)) {
        y = rand() % 2 + 1;
        if (rand() % 2 == 0) {
            y = y * -1;
        }
    }
    if( y + dir_y == _upperBound || y + dir_y == _lowerBound ) {
        dir_updown = dir_updown * -1;
        dir_y = dir_y * -1;
    }
    if( x + dir_x == _userBound || x + dir_x == _cpuBound) {
        dir_leftright = dir_leftright * -1;
        dir_x = dir_x * -1;
    }
    _x = x + dir_x;
    _y = y + dir_y;
}

void Ball::ChangeDir(float _newdir) {
    if (dir_x > 0) {
        dir_x = dir_leftright = _newdir;
    } else {
        dir_x = dir_leftright = _newdir * -1;
    }
}
