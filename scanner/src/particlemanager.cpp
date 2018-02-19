//
//  particlemanager.cpp
//  scanner
//
//  Created by jlsy012 on 2018. 2. 19..
//

#include "particlemanager.h"


// private member property area /////////////////////////////////

void JLParticleManager::initDefaultData()
{
    ;
    
}

// public member property area //////////////////////////////////

// private member method area ///////////////////////////////////

// public member method area ////////////////////////////////////

JLParticleManager::JLParticleManager()
{
    initDefaultData();
}

JLParticleManager::~JLParticleManager()
{
    ;
}

void JLParticleManager::addParticle(vector<ofPoint> points)
{
    JLParticle *particle;
    
    particle = new JLParticle(points , JLGlob::shared()->scrWidth , JLGlob::shared()->scrHeight);
    
    particles.push_back(*particle);
}

void JLParticleManager::update()
{
    for(int i=0;i<particles.size();i++)
    {
        particles[i].update();
    }
}

void JLParticleManager::draw()
{
    for(int i=0;i<particles.size();i++)
    {
        particles[i].draw();
    }
}

// public event handling area //////////////////////////////////


