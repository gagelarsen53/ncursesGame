/* 
 * File:   Ball.h
 * Author: mikewright
 *
 * Created on August 14, 2014, 9:04 AM
 */

#ifndef BALL_H
#define	BALL_H

#include "IRenderable.h"
#include <math.h>
#include <unistd.h>
class Ball : public IRenderable {
private:
    int _x, _y, _upperBound, _lowerBound, _userBound, _cpuBound;
    float dir_updown, dir_leftright, dir_x, dir_y;
    
public:
    Ball();
    Ball(const Ball& orig);
    virtual ~Ball();

    virtual void Render();
    virtual int GetX();
    virtual int GetY();
    virtual int GetUpperBound();
    virtual int GetLowerBound();
    virtual int GetYDir();
    virtual int GetXDir();
    
    void Init(int x, int y, int upperBound, int lowerBound, int userBound, int cpuBound);
    void Move(float x=NAN, float y=NAN);
    void ChangeDir(float _newdir);
};

#endif	/* BALL_H */

