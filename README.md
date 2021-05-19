# ofxSurfingDebug

An **openFrameworks** add-on to subscribe, debug and print some variables of your **ofApp** during runtime without any required updating.
 
Based in the original add-on:  
https://github.com/tettou771/ofxHelpMessage from [**Toru Takata**](https://github.com/tettou771)

You can add variables and text messages too.

Added variables (string, float, int, bool) are referenced, and can be showed in realtime in the same text box.  
You dont need to update nothing.

The class uses a singleton, so you can add referenced variables (or text) from any of your included classes.  
You just need to add this header to your classes.  
when using multiple instances, 
All classes will "share" the same text box.

## Screenshot
![screenshot](readme_images/screenshot.jpg?raw=true "moebiusSurfing")

## Usage
1. Include `ofxSurfingDebug.h`.
2. Put the static methods like `ofxSurfingDebug::addText("saveKey", "Key S: save");` in setup().
3. During runtime press '?' key to show text box.
4. Done! All your added variables will be printed to the screen on every frame.

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

// set tittle
ofxSurfingDebug::setTitle("APP INFO");

// add/subscribe variables:

// name is not used in this type. no variable, just the string text
ofxSurfingDebug::addText("KEY [SPACE]: HIDE/SHOW");//not required name on text type
//ofxSurfingDebug::addText("noName", "KEY [SPACE]: HIDE/SHOW");

// add empty line to make space
//ofxSurfingDebug::addNewLine();

// add the referenced variables that you what to show printed in the screen box
// pass all variables as reference
ofxSurfingDebug::addString("myString1", &str1);ofxSurfingDebug::addFloat("myFloat1 ", &f1);
ofxSurfingDebug::addInt("myInt1", &i1);
ofxSurfingDebug::addBool("myBool1", &b1);

// float parameter. only for float for now.
ofxSurfingDebug::addParamFloat(floatParam);

// control:
// change show text box key
//ofxSurfingDebug::setMomentary(true);
//ofxSurfingDebug::setHelpKey('d');


// customize style:
// show
//ofxSurfingDebug::setVisible(true);
// round bbox
//ofxSurfingDebug::setRounded(true, 5.0f);
// set margin borders
//ofxSurfingDebug::setMarginBorders(20);
// tab label names and variable values aligned by columns
//ofxSurfingDebug::setTabbed(true, 1);

//--

update()

// your variables will change...
// but nothing more to do.
```

You can use this workaround to add ofParameters too:
```cpp 
ofParameter<float> floatParam;
ofxSurfingDebug::addFloat(floatParam.getName(), (float*)&floatParam.get());//get name from parameter

ofParameter<string> stringParam;
ofxSurfingDebug::addString("myString", (string*)&stringParam.get());//put your custom name
```

## Dependencies
* [ofxScaleDragRect](https://github.com/moebiussurfing/ofxScaleDragRect)

## Tested system
  - **Windows 10** / **VS 2017** / **OF ~0.11**
  - **macOS**. **High Sierra** / **Xcode9** & **Xcode10** / **OF ~0.11**

## More Customization
You can use some method to change appearance and behaviour.
For example.

```.cpp
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
+ Add more ofParameters types
+ Store/Recall position and settings to xml.
+ Enable multiple boxes or just split to another add-on without singleton.

## Fork author
An add-on by **@moebiusSurfing**  
*( ManuMolina ) 2019-2021* 

## Original Author
**Toru Takata** in Japan.  
[GitHub](https://github.com/tettou771)  
[Website Link](http://tettou771.com)  
