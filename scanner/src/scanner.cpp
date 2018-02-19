//
//  scanner.cpp
//  scanner
//
//  Created by jlsy012 on 2018. 2. 18..
//

#include "scanner.h"


// private member method area ///////////////////////////////////

void JLScanner::initDefaultData()
{
    camera      = new ofVideoGrabber();
    deviceImage = new ofImage();
    contourFinder = new ofxCvContourFinder();
    
    checkCamera();
}

void JLScanner::checkCamera()
{
    vector<ofVideoDevice> devices;
    
    devices = camera->listDevices();
    
    for(size_t i = 0; i < devices.size(); i++)
    {
        if(devices[i].bAvailable)
        {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }
        else
        {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    /*
     camera->setDeviceID(0);
     camera->setDesiredFrameRate(30);
     camera->initGrabber(1920,1080);
     camera->initGrabber(1920,1080);
     */
}

void JLScanner::loadTestImage()
{
    ofImage *fileImage;
    
    fileImage = new ofImage();
    
    fileImage->load("ticket.jpg");
    
    deviceImage->allocate(fileImage->getWidth(), fileImage->getHeight() , OF_IMAGE_COLOR);
    
    deviceImage->setFromPixels(fileImage->getPixels());
    
    delete fileImage;
}

void JLScanner::extractGraph()
{
    int colorDiff;
    ofColor color;
    
    colorDiff = 0;
    
    for (int y=0;y<100;y++)
    {
        for (int x=0;x<deviceImage->getWidth();x++)
        {
            deviceImage->setColor(x, y, 0);
        }
    }
    
    for (int y=100;y<deviceImage->getHeight();y++)
    {
        for (int x=0;x<deviceImage->getWidth();x++)
        {
            color = deviceImage->getColor(x,y);
            
            colorDiff = (color.b - color.g - color.r);
            
            if (colorDiff < 80)
            {
                deviceImage->setColor(x, y, 0);
            }
            else
            {
                ;//ofLog() << colorDiff;
            }
        }
    }
    
    deviceImage->update();
}

void JLScanner::simpleApproxPolyDP(const vector<ofPoint>& contourIn, vector<ofPoint>& contourOut, float tolerance)
{
    int index;
    int numOfPoints;
    CvPoint* cvpoints;
    CvContour contour;
    CvSeqBlock contour_block;
    CvMemStorage* storage;
    CvPoint * pt;
    CvSeq *result = 0;
    
    numOfPoints = contourIn.size();
    
    cvpoints = new CvPoint[numOfPoints];
    
    for( int i=0; i<numOfPoints; i++)
    {
        index = i % numOfPoints;
        
        cvpoints[i].x = contourIn[index].x;
        cvpoints[i].y = contourIn[index].y;
    }
    
    cvMakeSeqHeaderForArray(CV_SEQ_POLYLINE,sizeof(CvContour),sizeof(CvPoint),cvpoints,numOfPoints,(CvSeq*)&contour,&contour_block);
    
    printf( "length = %f \n", cvArcLength(&contour));
    
    storage = cvCreateMemStorage(1000);
    
    result = cvApproxPoly(&contour,sizeof(CvContour),storage,CV_POLY_APPROX_DP,tolerance,0);
    
    contourOut.clear();
    
    for( int i=0; i<result->total-1; i++ )
    {
        pt = (CvPoint*)cvGetSeqElem(result, i);

        contourOut.push_back(ofPoint());
        contourOut.back().x = (float)pt->x;
        contourOut.back().y = (float)pt->y;
    }
    
    if( storage != NULL )
    {
        cvReleaseMemStorage(&storage);
    }
    
    delete[] cvpoints;
}


void JLScanner::findContour()
{
    int count;
    
    ofxCvColorImage colorImage;
    
    grayImage  = new ofxCvGrayscaleImage();
    
    colorImage.allocate(deviceImage->getWidth(), deviceImage->getHeight());
    grayImage->allocate(deviceImage->getWidth(), deviceImage->getHeight());
    
    colorImage.setFromPixels(deviceImage->getPixels());
    
    *grayImage = colorImage;
    
    grayImage->blurGaussian();
    
    count = contourFinder->findContours(*grayImage, 0, (grayImage->width*grayImage->height) , 4, false,true);
    
    ofLog() << "Found contours = " << count;
    ofLog() << "Blos = " << contourFinder->nBlobs;
    
    for (int i=0;i<contourFinder->blobs.size();i++)
    {
        ofLog() << i << " , " << contourFinder->blobs[i].boundingRect.x  << " , " << contourFinder->blobs[i].boundingRect.y  << " , " << contourFinder->blobs[i].boundingRect.width  << " , " << contourFinder->blobs[i].boundingRect.height  << " , " << contourFinder->blobs[i].boundingRect.getArea();
    }
  
    simpleApproxPolyDP(contourFinder->blobs[0].pts , graphPoints , 5);
    
    //https://bost.ocks.org/mike/simplify/0
    
    
    for(ofPoint pos : graphPoints)
    {
        ofLog() << "x : " << pos.x << " y : " << pos.y;
    }
}

void JLScanner::procFinalImage()
{
    extractGraph();
    
    findContour();
}

// public member method area ////////////////////////////////////

JLScanner::JLScanner()
{
    initDefaultData();
}

JLScanner::~JLScanner()
{
    delete camera;
    delete deviceImage;
}

void JLScanner::takeTicket()
{
    loadTestImage();// for test
    
    procFinalImage();
}

void JLScanner::refresh()
{
    //deviceImage->draw(0,0);
    
    grayImage->draw(0,0);
    contourFinder->draw(0,0);
    
    for(ofPoint pos : graphPoints)
    {
        ofDrawEllipse(pos.x, pos.y, 10, 10);
    }
}






// public event handling area //////////////////////////////////



