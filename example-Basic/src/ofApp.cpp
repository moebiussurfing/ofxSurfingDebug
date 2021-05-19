#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);

	// add variabes

	title = "APP INFO\n";
	ofxSurfingDebug::setTitle(title);

	// name not showed in text type
	ofxSurfingDebug::addText("HELP :");
	ofxSurfingDebug::addText("KEY [SPACE] : HIDE/SHOW");
	ofxSurfingDebug::addText("these are hardcoded text lines");
	ofxSurfingDebug::addNewLine();

	ofxSurfingDebug::addText("DEBUG:");
	ofxSurfingDebug::addString("myString2", &str2);
	ofxSurfingDebug::addFloat("myFloat1", &f1);
	ofxSurfingDebug::addFloat("myFloat2", &f2);
	ofxSurfingDebug::addFloat("myFloat3", &f3);
	ofxSurfingDebug::addString("myString1", &str1);
	ofxSurfingDebug::addText("these are referenced variables");
	ofxSurfingDebug::addNewLine();

	ofxSurfingDebug::addText("COUNTERS:");
	ofxSurfingDebug::addInt("myInt1 (frameNum)", &i1);
	ofxSurfingDebug::addInt("myInt2 (seconds)", &i2);
	ofxSurfingDebug::addFloat("myFloat4 ", &f4);
	ofxSurfingDebug::addNewLine();

	//ofParameters
	ofxSurfingDebug::addText("PARAMETERS:");
	ofxSurfingDebug::addParamFloat(myParamFloat);
	ofxSurfingDebug::addParamInt(myParamInt);
	ofxSurfingDebug::addText("these are ofParameters");
	ofxSurfingDebug::addNewLine();

	ofxSurfingDebug::addText("SWITCHES:");
	ofxSurfingDebug::addBool("myBool1", &b1);
	ofxSurfingDebug::addBool("myBool2", &b2);

	//----

	// extra cutomizations:

	// show box. hidden by default
	ofxSurfingDebug::setShowing(true);

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
	ofxSurfingDebug::loadFont(path, fontSize);

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
	ofxSurfingDebug::setFloatResolution(2);

	// round bbox
	ofxSurfingDebug::setRounded(false);

	// show fps
	ofxSurfingDebug::setShowFPS(true);

	// clear message
	//ofxSurfingDebug::clear();

	// set text color
	// default: ofColor::white
	//ofxSurfingDebug::setTextColor(ofColor(255, 255, 0));

	// set background color
	// default: ofColor(0, 0, 0, 150) this is black transparently
	//ofxSurfingDebug::setBackgroundColor(ofColor(0));
}

//--------------------------------------------------------------
void ofApp::exit() {
	ofxSurfingDebug::exit();
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
