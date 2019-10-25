//
//  ball.cpp
//  expression
//
//  Created by ICE on 10/24/19.
//

#include "ball.hpp"
Ball::Ball(){
}

void Ball::setup(float _x, float _y, int _dim){
    x = _x;
    y = _y;
    dim = _dim;
//    speedX = ofRandom(-1, 1);
//    speedY = ofRandom(-1, 1);
}

void Ball::draw(float x, float y, int dim){
    ofDrawCircle(x, y, dim);
}
