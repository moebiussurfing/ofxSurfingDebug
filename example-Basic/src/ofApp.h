#pragma once

#include "ofMain.h"
#include "ofxSurfingDebug.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    float fontSize = 9;

    string title;
    string str1, str2;
    float f1, f2, f3, f4;
    int i1, i2;
    bool b1, b2;

};
