#include "ofApp.h"



// private member method area ///////////////////////////////////


void ofApp::initDefaultData()
{
    ofBackground(0);
    
    myScanner = new JLScanner();
    particleManager = new JLParticleManager();
    
    myScanner->takeTicket();
    
    particleManager->addParticle(myScanner->getVertex());
}



// public member method area ////////////////////////////////////



//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(1400, 900); // just for test
    
    JLGlob::shared()->scrWidth  = ofGetScreenWidth();
    JLGlob::shared()->scrHeight = ofGetScreenHeight();
    
    
    initDefaultData();
}

//--------------------------------------------------------------
void ofApp::update()
{
    particleManager->update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetBackgroundColor(0, 0, 0);
    
    //myScanner->refresh();
    
    particleManager->draw();
}


// public event handling area //////////////////////////////////


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
