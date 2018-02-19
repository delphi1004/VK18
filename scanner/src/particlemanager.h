//
//  particlemanager.hpp
//  scanner
//
//  Created by jlsy012 on 2018. 2. 19..
//

#ifndef particlemanager_hpp
#define particlemanager_hpp

#include "ofMain.h"
#include "particle.h"
#include "global.h"

class JLParticleManager
{
    
    // private member property area /////////////////////////////////
    
private:
    
    vector<JLParticle> particles;
    
    
    // public member property area //////////////////////////////////
    
    // private member method area ///////////////////////////////////
    
    void initDefaultData();
    
    // public member method area ////////////////////////////////////
    
public:
    
    JLParticleManager();
    ~JLParticleManager();
    
    void addParticle(vector<ofPoint> points);
    void update();
    void draw();
    
    // public event handling area //////////////////////////////////
    
};


#endif /* particlemanager_hpp */
