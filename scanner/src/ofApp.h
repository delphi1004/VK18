////////////////////////////////////////////////////////////////////////
//
// This is a module for scan card by John Lee. 09 Jan 2018
//
//
//
//
//
//
// private member property area /////////////////////////////////

// public member property area //////////////////////////////////

// private member method area ///////////////////////////////////

// public member method area ////////////////////////////////////

// public event handling area //////////////////////////////////
//
////////////////////////////////////////////////////////////////////////



#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
    
    // private member property area /////////////////////////////////
    
    // public member property area //////////////////////////////////
    
    // private member method area ///////////////////////////////////
    
    // public member method area ////////////////////////////////////
    
    public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    // public event handling area //////////////////////////////////

	
};
