//
//  Rect.cpp
//  Era
//
//  Created by koutaro fukui on 2012/11/04.
//
//

#include "Rect.h"

rect::rect(ofPoint _pos, float _w, int _h){
    
    pos = ofPoint(_pos);
    w = _w;
    h = _h;
    
}

rect::~rect()
{
    
}

void rect::update(){
    
}
ofPoint rect::getPos()
{
    return pos;
}

float rect::getWidth(){
    return w;
}

void rect::setPos(ofPoint _pos)
{
    pos = _pos;
}
void rect::setWidth(float _w)
{
    w = _w;
}

void rect::draw(){
    
    ofSetColor(255, 255, 255);
    ofRect(pos.x, pos.y, w, h);
    
}