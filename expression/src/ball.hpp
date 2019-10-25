//
//  ball.hpp
//  expression
//
//  Created by ICE on 10/22/19.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include "ofMain.h"

class Ball {
    public:

    void update();
    void draw(float x, float y, int dim);
    void setup(float _x, float _y, int _dim);

    float x;
    float y;
    float speedY;
    float speedX;
    int dim;

    ofColor color;

    Ball();
};
#endif /* ball_hpp */
