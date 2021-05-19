#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    ofSetFrameRate(25);

    // add message

    title = "APP INFO                  \n";//+spaces to avoid resizing on bbox
    ofxSurfingDebug::setTitle(title);

    //name not showed in text type
    ofxSurfingDebug::addText("text1", "HELP:");
    ofxSurfingDebug::addText("text2", "KEY [SPACE]: HIDE/SHOW");
    ofxSurfingDebug::addText("text3", "");

    ofxSurfingDebug::addText("text4", "DEBUG:");
    ofxSurfingDebug::addString("myString2", &str2);
    ofxSurfingDebug::addFloat("myFloat1 ", &f1);
    ofxSurfingDebug::addFloat("myFloat2 ", &f2);
    ofxSurfingDebug::addFloat("myFloat3 ", &f3);
    ofxSurfingDebug::addString("myString1", &str1);

    ofxSurfingDebug::addText("text", "\nCOUNTERS:");
    ofxSurfingDebug::addInt("myInt1   ", &i1);
    ofxSurfingDebug::addInt("myInt2   ", &i2);
    ofxSurfingDebug::addFloat("myFloat4 ", &f4);

    ofxSurfingDebug::addText("text", "\nSWITCHES:");
    ofxSurfingDebug::addBool("myBool1  ", &b1);
    ofxSurfingDebug::addBool("myBool2  ", &b2);

    // clear message
    //ofxSurfingDebug::clear();

    // set text color
    // default: ofColor::white
    //ofxSurfingDebug::setTextColor(ofColor(255, 255, 0));

    // set background color
    // default: ofColor(0, 0, 0, 150) this is black transparently
    //ofxSurfingDebug::setBackgroundColor(ofColor(0));

    // set font
    // draw with ofTrueTypeFont if loaded
    //ofxSurfingDebug::loadFont("arial.ttf", fontSize);
    //ofxSurfingDebug::loadFont("overpass-mono-light.otf", fontSize);
	ofxSurfingDebug::loadFont("mono.ttf", fontSize);

    // set position
    // default: (10, 10)
    //ofxSurfingDebug::setPos(10, 10);

    // change show message key
    // default: '?'
    ofxSurfingDebug::setHelpKey(' ');

    // set show mode to momentary/toggle
    // default: true (momentary)
    ofxSurfingDebug::setMomentary(false); // toggle mode


    // set margin borders
    // default 5
    ofxSurfingDebug::setMarginBorders(20);

    // tab labels and values
    ofxSurfingDebug::setTabbed(true, 1);

    // float decimals
    ofxSurfingDebug::setFloatResolution(1);

    // round bbox
    //ofxSurfingDebug::setRounded(true);

	// show fps
	ofxSurfingDebug::setShowFPS(true);

    // show box. hidden by default
    ofxSurfingDebug::setShowing(true);
}

//--------------------------------------------------------------
void ofApp::update() {
    // nothing to do

    ///-

    //make random changes to our variables to demo

    int time = ofGetFrameNum();

    //string
    int myRandom = ofRandom(0,5);
    switch (myRandom) {
        case 0:
            str1 = "|----";
            break;
        case 1:
            str1 = "-|---";
            break;
        case 2:
            str1 = "--|--";
            break;
        case 3:
            str1 = "---|-";
            break;
        case 4:
            str1 = "----|";
            break;
        default:
            break;
    }

    //string
    str2 = ofToString(time);

    //floats
    f1 = ofRandom (0,1);
    f2 = ofRandom (0,1);
    f3 = ofRandom (0,1);
    f4 = ofRandom (0,1);

    //ints
    i1 = time;
    i2 = ofGetFrameNum() % 60;

    //bools
    if (ofGetFrameNum() % 60) b1=!b1;
    if (myRandom == 4) b2=!b2;

}

//--------------------------------------------------------------
void ofApp::draw() {
    // nothing to show
}
