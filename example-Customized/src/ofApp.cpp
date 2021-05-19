#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);

	// add variabes

	title = "APP INFO\n";
	ofxSurfingDebugVariables::setTitle(title);

	// name not showed in text type
	ofxSurfingDebugVariables::addText("HELP :");
	ofxSurfingDebugVariables::addText("KEY [SPACE] : HIDE/SHOW");
	ofxSurfingDebugVariables::addText("these are hardcoded text lines");
	ofxSurfingDebugVariables::addNewLine();

	ofxSurfingDebugVariables::addText("DEBUG:");
	ofxSurfingDebugVariables::addString("myString2", &str2);
	ofxSurfingDebugVariables::addFloat("myFloat1", &f1);
	ofxSurfingDebugVariables::addFloat("myFloat2", &f2);
	ofxSurfingDebugVariables::addFloat("myFloat3", &f3);
	ofxSurfingDebugVariables::addString("myString1", &str1);
	ofxSurfingDebugVariables::addText("these are referenced variables");
	ofxSurfingDebugVariables::addNewLine();

	ofxSurfingDebugVariables::addText("COUNTERS:");
	ofxSurfingDebugVariables::addInt("myInt1 (frameNum)", &i1);
	ofxSurfingDebugVariables::addInt("myInt2 (seconds)", &i2);
	ofxSurfingDebugVariables::addFloat("myFloat4 ", &f4);
	ofxSurfingDebugVariables::addNewLine();

	//ofParameters
	ofxSurfingDebugVariables::addText("PARAMETERS:");
	ofxSurfingDebugVariables::addParamFloat(myParamFloat);
	ofxSurfingDebugVariables::addParamInt(myParamInt);
	ofxSurfingDebugVariables::addText("these are ofParameters");
	ofxSurfingDebugVariables::addNewLine();

	ofxSurfingDebugVariables::addText("SWITCHES:");
	ofxSurfingDebugVariables::addBool("myBool1", &b1);
	ofxSurfingDebugVariables::addBool("myBool2", &b2);

	//----

	// extra cutomizations:

	// show box. hidden by default
	ofxSurfingDebugVariables::setShowing(true);

	// customize font

	// size
	fontSize = 10;
	//fontSize = 9;

	// draws with ofTrueTypeFont if loaded
	string path = "assets/fonts/";
	path += "overpass-mono-bold.otf";
	//path += "Kazesawa-Extrabold.ttf";
	//path += "mono.ttf";
	//path += "arial.ttf";
	ofxSurfingDebugVariables::loadFont(path, fontSize);

	// set position
	// default: (10, 10)
	//ofxSurfingDebugVariables::setPos(10, 10);

	// change show message key
	// default: '?'
	ofxSurfingDebugVariables::setHelpKey(' ');

	// set show mode to momentary/toggle
	// default: true (momentary)
	ofxSurfingDebugVariables::setMomentary(false); // toggle mode


	// set margin borders
	// default 5
	ofxSurfingDebugVariables::setMarginBorders(20);

	// tab labels and values
	ofxSurfingDebugVariables::setTabbed(true, 1);

	// float decimals
	ofxSurfingDebugVariables::setFloatResolution(2);

	// round bbox
	ofxSurfingDebugVariables::setRounded(false);

	// show fps
	ofxSurfingDebugVariables::setShowFPS(true);

	// clear message
	//ofxSurfingDebugVariables::clear();

	// set text color
	// default: ofColor::white
	//ofxSurfingDebugVariables::setTextColor(ofColor(255, 255, 0));

	// set background color
	// default: ofColor(0, 0, 0, 150) this is black transparently
	//ofxSurfingDebugVariables::setBackgroundColor(ofColor(0));
}

//--------------------------------------------------------------
void ofApp::exit() {
	ofxSurfingDebugVariables::exit();
}

//--------------------------------------------------------------
void ofApp::update() {
	// nothing more to do

	// simulate artificial variations on our variables
	// make random changes to our variables to demo

	auto time = ofGetFrameNum();

	// string
	float myRandom = ofNoise(time / 60.f, 2);
	switch ((int) (5 * myRandom)) {
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

	// string
	str2 = ofToString(time);

	// floats
	f1 = ofRandom(0, 1);
	f2 = ofRandom(0, 1);
	f3 = ofRandom(0, 1);
	f4 = ofRandom(0, 1);

	// ints
	i1 = time;
	i2 = ofGetFrameNum() % 60;

	if (ofGetFrameNum() % 60 == 0)
	{
		// bool
		b1 = !b1;

		// param float
		myParamFloat = ofRandom(myParamFloat.getMin(), myParamFloat.getMax());
	}

	// param int
	myParamInt = ofMap(myRandom * myParamInt.getMax(), 0, 1, myParamInt.getMin(), myParamInt.getMax());

	// bool
	if (myRandom == 4) b2 = !b2;

}

//--------------------------------------------------------------
void ofApp::draw() {
	// nothing more
}
