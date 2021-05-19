#pragma once
#include "ofMain.h"

#include "ofxSurfingDebugVariables.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();

    string title;
    string str1, str2;
    float f1, f2, f3, f4;
    int i1, i2;
    bool b1, b2;
	ofParameter<float> myParamFloat{ "myParamFloat", 0, 0, 1 };
	ofParameter<int> myParamInt{ "myParamInt", 0, -10, 10 };

    float fontSize;
};
