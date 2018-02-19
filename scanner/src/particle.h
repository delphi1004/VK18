//
//  particle.hpp
//  scanner
//
//  Created by jlsy012 on 2018. 2. 19..
//

#ifndef particle_hpp
#define particle_hpp

// private member property area /////////////////////////////////

// public member property area //////////////////////////////////

// private member method area ///////////////////////////////////

// public member method area ////////////////////////////////////

// public event handling area //////////////////////////////////
//
////////////////////////////////////////////////////////////////////////


#include "ofMain.h"

class JLParticle
{
    // private member property area /////////////////////////////////
    
private:
    
    vector<ofPoint> vertexList;
    ofPoint position;
    ofPoint velocity;
    int workingWidth;
    int workingHeight;
    int temp;
    float curAngle;
    
    
    // public member property area //////////////////////////////////
    
    
    // private member method area ///////////////////////////////////
    
    void initDefaultData();
    void move();
    void showMe();

    
    // public member method area ////////////////////////////////////
    
public:
    
    JLParticle(vector<ofPoint> points, int width, int height);
    ~JLParticle();
    
    void update();
    void draw();
    
    
    
    
    // public event handling area //////////////////////////////////

};

#endif /* particle_hpp */
