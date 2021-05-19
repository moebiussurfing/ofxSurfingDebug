#pragma once
#include "ofMain.h"
#include "ofxInteractiveRect.h"

//TODO:
//+ add auto position from bottom + offset

class ofxSurfingDebug
{
private:
    ofxSurfingDebug();
    ~ofxSurfingDebug();

public:
	ofxInteractiveRect myRect = { "myRect" };
	static void exit();

public:
    enum MSG_TYPES{
        MSG_TITLE = 0,
        MSG_TEXT,
        MSG_STRING,
        MSG_FLOAT,
        MSG_INT,
        MSG_BOOL,
		MSG_PARAM_FLOAT, 
		MSG_PARAM_INT 
    };

    static void setTitle(string _title);

	static void addNewLine();

	static void addText(string _message, bool _newLine = true);
	static void addText(string name, string _message, bool _newLine = true);
	
	static void addString(string name, string *label, bool _newLine = true);
    static void addFloat(string name, float *var, bool _newLine = true);
    static void addInt(string name, int *var, bool _newLine = true);
    static void addBool(string name, bool *var, bool _newLine = true);

	//TODO:
	//add abstractParameter
	//static void addParamFloat(ofParameter<float> *p, bool _newLine = true);
	static void addParamFloat(ofParameter<float> p, bool _newLine = true);
	static void addParamInt(ofParameter<int> p, bool _newLine = true);

    ///-

    void draw(ofEventArgs &e);
    void keyPressed(ofKeyEventArgs& key);

    // static function

    static void clear();
  
	static void setHelpKey(char _key);
    static char getHelpKey();
    static void setMomentary(bool _momentary);
    static bool getMomentary();
    static bool getSwhoing();
	static void setShowing(bool _showing);

    static void loadFont(string _path, float _size);

	static void setPos(ofVec2f _pos, bool bTopAlign = true);
	static void setPos(float _x, float _y, bool bTopAlign = true);
	static ofVec2f getPos();
	static ofVec2f getSize();

	static void setTextColor(ofColor _color);
	static ofColor getTextColor();
	static void setBackgroundColor(ofColor _color);
	static ofColor getBackgroundColor();

	static void setBackgroundAlpha(int _alpha);

    static void setTabbed(bool b, int num = 1);
    static void setFloatResolution(int res = 2);
    static void setMarginBorders(int _margin);
    static void setRounded(bool b, float size = 10.0f);

	static void setShowFPS(bool _showing);

private:

//    unordered_map<string, double> maptest;

    static ofxSurfingDebug *singleton;
    static void singletonGenerate();
    ofMutex mutex;
	bool initialized;
	    
    char helpKey;
    bool showing, momentary;
	bool BBoxShowing;
    ofColor textColor, bgColor;
    ofVec2f pos;
    ofVec2f drawPos;
	bool bTopAlign;

    ofTrueTypeFont font;

    void updateDrawPos();

    //-

    string messageBox;

    struct MSG_Item {
        string name;
        MSG_TYPES type;
        int position;
    };
    vector<MSG_Item> items;

    std::string title;
    vector<std::string> messages;
    vector<std::string*> strings;
    vector<float *> floats;
    vector<int *> ints;
    vector<bool *> bools;

	//params
	//could be better to use pointers..?
	//vector<ofParameter<float>*> paramsFloats;
	vector<ofParameter<float>> paramsFloats;
	vector<ofParameter<int>> paramsInt;

    void updateItems();

	//TODO:
	//improve columns alignment
	int maxChars;

	//add defined number of to separate names from values
	//void fillTabs(string &m)
	//{
	//	if (bTabbed)
	//	{
	//		for (int i = 0; i < tabsNum; i++)
	//		{
	//			singleton->m += " \t ";
	//		}
	//	}
	//}

	//fill all names with same size to align columns
	void fillName(string &str)
	{
		int size = str.size();
		int numSpacesToAdd = maxChars - size;
		for (int i = 0; i < numSpacesToAdd; i++)
		{
			str += " ";
		}
	}

    ///-

    //layout
    bool bTabbed = false;
    int tabsNum = 1;
    int fRes = 2;
    int margin = 5;
    bool bRounded = false;
    float roundedSize = 10.0f;
	bool showFPS;

    ofRectangle rectBB;
};

