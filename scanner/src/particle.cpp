//
//  particle.cpp
//  scanner
//
//  Created by jlsy012 on 2018. 2. 19..
//

#include "particle.h"


// private member method area ///////////////////////////////////

void JLParticle::initDefaultData()
{
    curAngle = 0;
    
    position.set(ofRandom(workingWidth), ofRandom(workingHeight));
    
    velocity.set(ofRandom(0.1,3), ofRandom(0.1,3));
    
    ofLog() << "New particle : " << position.x << "," << position.y;
}

void JLParticle::move()
{
    position += velocity;
    
    //ofLog() << position.x << "," << position.y;
    
    if (position.x >= workingWidth || position.x <= 0)
    {
        if (velocity.y < 0)
        {
            curAngle += 50;
        } else
        {
            curAngle -= 50;
        }
        
        velocity.x *= -1;
    }
    
    if (position.y  >= workingHeight || position.y <= 0)
    {
        if (velocity.x < 0)
        {
            curAngle += 50;
        } else
        {
            curAngle -= 5;
        }
        
        velocity.y *= -1;
    }
}

void JLParticle::showMe()
{
    ofSetColor(255, 255, 255);
    
    ofPushMatrix();
    
    ofTranslate(position.x, position.y);
    
    ofRotate(curAngle);
    
    for (ofPoint pos : vertexList)
    {
        ofDrawEllipse(pos.x, pos.y, 10, 10);
    }
    
    ofPopMatrix();
}

// public member method area ////////////////////////////////////

JLParticle::JLParticle(vector<ofPoint> points, int width, int height)
{
    vertexList = points;
    
    workingWidth = width;
    workingHeight = height;
    
    initDefaultData();
}

JLParticle::~JLParticle()
{
    ;
}

void JLParticle::update()
{
    move();
}

void JLParticle::draw()
{
    showMe();
}

// public event handling area //////////////////////////////////
