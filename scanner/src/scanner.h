//
//  scanner.hpp
//  scanner
//
//  Created by jlsy012 on 2018. 2. 18..
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

#ifndef scanner_h
#define scanner_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "imgproc_c.h"
#include "imgproc.hpp"
#include "core.hpp"
#include "mat.hpp"

class JLScanner
{
    
    
    // private member property area /////////////////////////////////
    
private:
    
    ofVideoGrabber *camera;
    ofImage *deviceImage;
    ofxCvContourFinder *contourFinder;
    ofxCvGrayscaleImage *grayImage;
    vector<ofPoint> graphPoints;
    ofPoint centerGraph;
    
    
    // public member property area //////////////////////////////////
    
    
    
    // private member method area ///////////////////////////////////
    
    void initDefaultData();
    void checkCamera();
    void loadTestImage();
    void procFinalImage();
    void simpleApproxPolyDP(const vector<ofPoint>& contourIn, vector<ofPoint>& contourOut, ofPoint center , float tolerance);
    
    
    // public member method area ////////////////////////////////////
    
public:
    
    JLScanner();
    ~JLScanner();
    void update();
    void draw();
    void takeTicket();
    void extractGraph();
    void findContour();
    vector<ofPoint> getVertex();
    
    
    
    // public event handling area //////////////////////////////////
    
    
};

#endif /* scanner_h */
