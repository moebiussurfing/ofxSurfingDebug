# ofxSurfingDebug

This is an openFrameworks addon to debug and print some variables of your ofApp in runtime without the need of updating anything.
 
Based in the original addon: https://github.com/tettou771/ofxHelpMessage from Toru Takata (https://github.com/tettou771)

You can add text messages and variables too.

Added variables (string, float, int, bool) are referenced, and can be showed in realtime in the same text box.
You dont need to update nothing.

The class uses a singleton, so you can add referenced variables (or text) from any of your included classes. You just need to add this header to your classes. All classes will "share" the same text box.


![Alt text](/screenshot.jpg?raw=true "MoebiusSurfing")


## Usage

1. Add this addon to your project.
1. Include `ofxSurfingDebug.h`.
1. Put the static methods like `ofxSurfingDebug::addText("saveKey", "Key S: save");` in setup().
1. When program running, press '?' key to show text box.
1. All your added variables will be printed to the screen text box.

### ofApp.h
```cpp
    #include "ofxSurfingDebug.h"

    string st1;
    float f1;
    int i1;
    bool b1;
    ofParameter<float> floatParam;
```

### ofApp.cpp
```cpp 

setup()

    // set first line tittle
    ofxSurfingDebug::setTitle("APP INFO                \n");
    
    // add variables:

    // name is not used in this type. no variable, just the string text
    ofxSurfingDebug::addText("KEY [SPACE]: HIDE/SHOW");//not required name on text type
	//ofxSurfingDebug::addText("noName", "KEY [SPACE]: HIDE/SHOW");
    
    //add empty line to make space
    ofxSurfingDebug::addNewLine();

    // add the referenced variables that you what to show printed in the screen box
    // pass all variables as reference
    ofxSurfingDebug::addString("myString1", &str1);ofxSurfingDebug::addFloat("myFloat1 ", &f1);
    ofxSurfingDebug::addInt("myInt1", &i1);
    ofxSurfingDebug::addBool("myBool1", &b1);
    
    // float parameter. only for float yes for now. get the name from the parameter
    ofxSurfingDebug::addParamFloat(floatParam);


	// control:

	// change show text box key
    //ofxSurfingDebug::setMomentary(true);
    //ofxSurfingDebug::setHelpKey('d');
    

    // customize style:

    // show
    ofxSurfingDebug::setVisible(true);
    // round bbox
    ofxSurfingDebug::setRounded(true, 5.0f);
    // set margin borders
    ofxSurfingDebug::setMarginBorders(20);
    // tab label names and variable values aligned by columns
    ofxSurfingDebug::setTabbed(true, 1);
    
update()

    //your variables will change...
    //but nothing more to do.
```

You can use this workaround to add ofParameters too:
```cpp 
ofParameter<float> floatParam;
ofxSurfingDebug::addFloat(floatParam.getName(), (float*)&floatParam.get());//get name from parameter

ofParameter<string> stringParam;
ofxSurfingDebug::addString("myString", (string*)&stringParam.get());//put your custom name
```


## Tested system

I think compatible almost all platforms, because it's a simple addon.
- Windows 10 / VS2017 / OF 0.11.0
- macOS / High Sierra / Xcode / OF 0.11.0


## More Customization

You can use some method to change appearance and behaviour.
For example.

```cpp
// clear message
//ofxSurfingDebug::clear();

// set text color
// default: ofColor::white
ofxSurfingDebug::setTextColor(ofColor(255, 255, 0));

// set background color
// default: ofColor(0, 0, 0, 150) this is black transparently
ofxSurfingDebug::setBackgroundColor(ofColor(0));

// set font
// draw with ofTrueTypeFont if loaded
ofxSurfingDebug::loadFont("arial.ttf", 30);

// set position
// default: (10, 10)
ofxSurfingDebug::setPos(500, 500);

```

### TODO:

+ add ofParameters
+ enable drag box position by mouse.
+ store/recall position and settings to xml.
+ enable multiple boxes or just split to another addon without singleton.


## Original Author of ofxSurfingDebug

Toru Takata in Japan.

GitHub: https://github.com/tettou771

Link: http://tettou771.com


## Modified and splitted by MoebiusSurfing

GitHub: https://github.com/moebiussurfing

Link: https://www.instagram.com/moebiussurfing/