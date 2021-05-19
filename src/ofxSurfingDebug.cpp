#include "ofxSurfingDebug.h"

ofxSurfingDebug* ofxSurfingDebug::singleton;

void ofxSurfingDebug::setTitle(string _title)
{
	singletonGenerate();
	singleton->mutex.lock();

	singleton->title = _title;

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

void ofxSurfingDebug::addNewLine() {
	string name = "noName";

	singletonGenerate();
	singleton->mutex.lock();

	singleton->messages.push_back(" ");
	int pos = singleton->messages.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_TEXT, pos });

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

//name is hidden in MSG_TEXT types. maybe not required but could search item by name..
void ofxSurfingDebug::addText(string _message, bool _newLine) {
	string name = "noName";

	singletonGenerate();
	singleton->mutex.lock();

	singleton->messages.push_back(_message);
	int pos = singleton->messages.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_TEXT, pos });

	if (_message.size() > singleton->maxChars)
		singleton->maxChars = _message.size();

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

void ofxSurfingDebug::addText(string name, string _message, bool _newLine) {
	singletonGenerate();
	singleton->mutex.lock();

	singleton->messages.push_back(_message);
	int pos = singleton->messages.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_TEXT, pos });

	if (_message.size() > singleton->maxChars)
		singleton->maxChars = _message.size();

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

void ofxSurfingDebug::addString(string name, string *label, bool _newLine)
{
	singletonGenerate();
	singleton->mutex.lock();

	singleton->strings.push_back(label);
	int pos = singleton->strings.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_STRING, pos });

	if (name.size() > singleton->maxChars)
		singleton->maxChars = name.size();

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

void ofxSurfingDebug::addFloat(string name, float *var, bool _newLine)
{
	singletonGenerate();
	singleton->mutex.lock();

	singleton->floats.push_back(var);
	int pos = singleton->floats.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_FLOAT, pos });

	if (name.size() > singleton->maxChars)
		singleton->maxChars = name.size();

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

void ofxSurfingDebug::addInt(string name, int *var, bool _newLine)
{
	singletonGenerate();
	singleton->mutex.lock();

	singleton->ints.push_back(var);
	int pos = singleton->ints.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_INT, pos });

	if (name.size() > singleton->maxChars)
		singleton->maxChars = name.size();

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

void ofxSurfingDebug::addBool(string name, bool *var, bool _newLine)
{
	singletonGenerate();
	singleton->mutex.lock();

	singleton->bools.push_back(var);
	int pos = singleton->bools.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_BOOL, pos });

	if (name.size() > singleton->maxChars)
		singleton->maxChars = name.size();

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

void ofxSurfingDebug::addParamFloat(ofParameter<float> p, bool _newLine)
//void ofxSurfingDebug::addParamFloat(ofParameter<float> *p, bool _newLine)
{
	singletonGenerate();
	singleton->mutex.lock();

	//string name = p->getName();
	string name = p.getName();
	singleton->paramsFloats.push_back(p);
	int pos = singleton->paramsFloats.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_PARAM_FLOAT, pos });

	if (name.size() > singleton->maxChars)
		singleton->maxChars = name.size();

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

void ofxSurfingDebug::addParamInt(ofParameter<int> p, bool _newLine)
{
	singletonGenerate();
	singleton->mutex.lock();

	string name = p.getName();
	singleton->paramsInt.push_back(p);
	int pos = singleton->paramsInt.size() - 1;
	singleton->items.push_back(MSG_Item{ name, MSG_PARAM_INT, pos });

	if (name.size() > singleton->maxChars)
		singleton->maxChars = name.size();

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

//--

void ofxSurfingDebug::updateItems()
{
	//to read pointers every frame cycle
	singletonGenerate();
	singleton->mutex.lock();

	//title
	singleton->messageBox = "";
	singleton->messageBox += title;
	singleton->messageBox += "\n";

	//all variables
	int i = 0;
	for (auto &item : items)
	{
		switch (item.type) {

		case MSG_TEXT:
		{
			int ii = singleton->items[i].position;

			//name is hidden in MSG_TEXT types. maybe not require but could search item by name..
			if (false)
			{
				string n = singleton->items[i].name;
				fillName(n);

				singleton->messageBox += n;
				//singleton->messageBox += ":";
				if (bTabbed)
				{
					for (int i = 0; i < tabsNum; i++)
					{
						singleton->messageBox += "\t";
					}
				}
			}
			//value
			string v = singleton->messages[ii];
			singleton->messageBox += v;
			singleton->messageBox += "\n";
		}
		break;

		case MSG_STRING:
		{
			int ii = singleton->items[i].position;

			string n = singleton->items[i].name;
			fillName(n);

			string v = *singleton->strings[ii];
			singleton->messageBox += n;
			//singleton->messageBox += ":";
			if (bTabbed)
			{
				for (int i = 0; i < tabsNum; i++)
				{
					singleton->messageBox += "\t";
				}
			}
			//singleton->messageBox += ":";
			singleton->messageBox += v;
			singleton->messageBox += "\n";
		}
		break;

		case MSG_FLOAT:
		{
			int ii = singleton->items[i].position;

			string n = singleton->items[i].name;
			fillName(n);

			string v = ofToString(*singleton->floats[ii], fRes);
			singleton->messageBox += n;
			//singleton->messageBox += ":";
			if (bTabbed)
			{
				for (int i = 0; i < tabsNum; i++)
				{
					singleton->messageBox += "\t";
				}
			}
			//singleton->messageBox += ":";
			singleton->messageBox += v;
			singleton->messageBox += "\n";
		}
		break;

		case MSG_INT:
		{
			int ii = singleton->items[i].position;

			string n = singleton->items[i].name;
			fillName(n);

			string v = ofToString(*singleton->ints[ii]);
			singleton->messageBox += n;
			//singleton->messageBox += ":";
			if (bTabbed)
			{
				for (int i = 0; i < tabsNum; i++)
				{
					singleton->messageBox += "\t";
				}
			}
			//singleton->messageBox += ":";
			singleton->messageBox += v;
			singleton->messageBox += "\n";
		}
		break;

		case MSG_BOOL:
		{
			int ii = singleton->items[i].position;

			string n = singleton->items[i].name;
			fillName(n);

			string v = (*singleton->bools[ii] ? "TRUE" : "FALSE");
			singleton->messageBox += n;
			//singleton->messageBox += ":";
			if (bTabbed)
			{
				for (int i = 0; i < tabsNum; i++)
				{
					singleton->messageBox += "\t";
				}
			}
			//singleton->messageBox += ":";
			singleton->messageBox += v;
			singleton->messageBox += "\n";
		}
		break;

		case MSG_PARAM_FLOAT:
		{
			int ii = singleton->items[i].position;

			string n = singleton->items[i].name;
			fillName(n);

			//string v = ofToString(*singleton->paramsFloats[ii].get(), fRes);
			string v = ofToString(singleton->paramsFloats[ii].get(), fRes);
			singleton->messageBox += n;
			//singleton->messageBox += ":";
			if (bTabbed)
			{
				for (int i = 0; i < tabsNum; i++)
				{
					singleton->messageBox += "\t";
				}
			}
			//singleton->messageBox += ":";
			singleton->messageBox += v;
			singleton->messageBox += "\n";
		}
		break;

		case MSG_PARAM_INT:
		{
			int ii = singleton->items[i].position;

			string n = singleton->items[i].name;
			fillName(n);

			string v = ofToString(singleton->paramsInt[ii].get());
			singleton->messageBox += n;
			//singleton->messageBox += ":";
			if (bTabbed)
			{
				for (int i = 0; i < tabsNum; i++)
				{
					singleton->messageBox += "\t";
				}
			}
			//singleton->messageBox += ":";
			singleton->messageBox += v;
			singleton->messageBox += "\n";
		}
		break;

		default:
			break;
		}

		//next
		i++;
	}

	if (showFPS)
	{
		singleton->messageBox += "\n";
		singleton->messageBox += ofToString(ofGetFrameRate(), 0);
		singleton->messageBox += " FPS";
	}

	singleton->mutex.unlock();
	singleton->updateDrawPos();
}

///-

ofxSurfingDebug::ofxSurfingDebug() {
	showing = false;
	BBoxShowing = true;
	momentary = false;
	initialized = true;
	textColor = ofColor::white;
	bgColor = ofColor(0, 150);
	pos.set(10, 10);
	helpKey = '?';
	showFPS = false;
	bTabbed = false;

	messageBox = "";
	maxChars = 0;

	ofAddListener(ofEvents().draw, this, &ofxSurfingDebug::draw, OF_EVENT_ORDER_AFTER_APP);
	ofAddListener(ofEvents().keyPressed, this, &ofxSurfingDebug::keyPressed, OF_EVENT_ORDER_AFTER_APP);
	
	//draggable
	myRect.setAutoSave(true);
	//myRect.loadSettings();
	myRect.setLockResize(true);
	myRect.enableEdit();
	//myRect.setRect(200, 200, 200, 400);
}

ofxSurfingDebug::~ofxSurfingDebug() {
	ofRemoveListener(ofEvents().draw, this, &ofxSurfingDebug::draw);
	ofRemoveListener(ofEvents().keyPressed, this, &ofxSurfingDebug::keyPressed);
}

void ofxSurfingDebug::exit() {
	singletonGenerate();
	singleton->myRect.saveSettings("", "", false);
	//myRect.saveSettings("", "", false);
	//myRect.saveSettings();
}

void ofxSurfingDebug::draw(ofEventArgs& e) {

	if (myRect.isEditing()) {
		pos = ofVec2f(myRect.getX(), myRect.getY());
		//pos = ofVec2f(myRect.getX()+ margin, myRect.getY()+ margin);
	}

	ofEnableAlphaBlending();

	if (momentary) {
		showing = ofGetKeyPressed(helpKey);
	}

	if (showing) {
		updateItems();

		ofPushStyle();
		if (font.isLoaded()) {

			//// simply draw a yellow rectangle using our ofxInteractiveRect object.
			//// As it inherits from ofRectangle you can simply pass it to ofDrawRectangle(...)
			//ofSetColor(ofColor::red);
			//ofDrawRectangle(myRect);

			// the following call will draw the rectangle's edge handles when editing.
			// call it after drawing the rectangle, otherwise the edge handles might not be visible
			myRect.draw();

			//--

			//bbox
			if (BBoxShowing)
			{
				ofSetColor(bgColor);
				ofFill();

				//TODO:
				//coulb be done not in every frame but when added last variable
				//bbox
				//if(bTopAlign)
				rectBB = font.getStringBoundingBox(messageBox, drawPos.x, drawPos.y);
				//else
				//rectBB = font.getStringBoundingBox(messageBox, drawPos.x, ofGetHeight() - drawPos.y);

				rectBB.x -= margin;
				rectBB.y -= margin;
				rectBB.height += 2 * margin;
				rectBB.width += 2 * margin;

				//if (!myRect.isEditing()) 
				{
					myRect.set(rectBB.x + margin, rectBB.y + margin, rectBB.width, rectBB.height);
				}

				//to compensate pos after margin
				ofPushMatrix();
				ofTranslate(margin, margin);

				//rounded
				if (bRounded)
				{
					ofDrawRectRounded(rectBB, roundedSize);
				}
				else
				{
					ofDrawRectangle(rectBB);
				}
			}

			//text
			ofSetColor(textColor);

			if (bTopAlign)
				font.drawString(messageBox, drawPos.x, drawPos.y);
			else
				font.drawString(messageBox, drawPos.x, ofGetWindowHeight() - drawPos.y);

			ofPopMatrix();
		}
		else
		{
			if (bTopAlign)
				ofDrawBitmapStringHighlight(messageBox, drawPos, bgColor, textColor);
			else
				ofDrawBitmapStringHighlight(messageBox,
					ofVec2f(drawPos.x, ofGetHeight() - drawPos.y), bgColor, textColor);
		}
		ofPopStyle();
	}
}

void ofxSurfingDebug::keyPressed(ofKeyEventArgs& key) {
	if (!momentary && key.key == helpKey) {
		showing = !showing;
	}
}

void ofxSurfingDebug::clear() {
	singletonGenerate();
	singleton->messageBox = "";
}

void ofxSurfingDebug::setHelpKey(char _key) {
	singletonGenerate();
	singleton->helpKey = _key;
}

char ofxSurfingDebug::getHelpKey() {
	singletonGenerate();
	return singleton->helpKey;
}

void ofxSurfingDebug::setMomentary(bool _momentary) {
	singletonGenerate();
	singleton->momentary = _momentary;
	if (singleton->momentary) singleton->showing = ofGetKeyPressed(singleton->helpKey);
}

void ofxSurfingDebug::setShowing(bool _showing) {
	singletonGenerate();
	singleton->showing = _showing;
}

void ofxSurfingDebug::setShowFPS(bool _showing) {
	singletonGenerate();
	singleton->showFPS = _showing;
}

bool ofxSurfingDebug::getMomentary() {
	singletonGenerate();
	return 	singleton->momentary;
}

bool ofxSurfingDebug::getSwhoing() {
	singletonGenerate();
	return singleton->showing;
}

void ofxSurfingDebug::singletonGenerate() {
	if (singleton == nullptr) {
		singleton = new ofxSurfingDebug();
	}
}

void ofxSurfingDebug::updateDrawPos() {
	// calc position
	if (font.isLoaded()) {
		auto fontBoundingBox = singleton->font.getStringBoundingBox(messageBox, pos.x, pos.y);
		drawPos = pos * 2 - ofVec2f(fontBoundingBox.x, fontBoundingBox.y);
	}
	else {
		float lineHeight = 12;
		drawPos = pos + ofVec2f(0, lineHeight);
	}
}

//layout

//TODO: topAlign implementation
void ofxSurfingDebug::setPos(ofVec2f _pos, bool _bTopAlign) {
	singletonGenerate();
	singleton->pos.set(_pos);
	singleton->bTopAlign = _bTopAlign;
	singleton->updateDrawPos();
}

void ofxSurfingDebug::setPos(float _x, float _y, bool _bTopAlign) {
	singleton->bTopAlign = _bTopAlign;
	setPos(ofVec2f(_x, _y));
}

ofVec2f ofxSurfingDebug::getPos() {
	singletonGenerate();
	return singleton->pos;
}

ofVec2f ofxSurfingDebug::getSize() {
	singletonGenerate();
	ofVec2f size = ofVec2f(singleton->rectBB.width, singleton->rectBB.height);
	return size;
}

//colors
void ofxSurfingDebug::setTextColor(ofColor _color) {
	singletonGenerate();
	singleton->textColor.set(_color);
}

ofColor ofxSurfingDebug::getTextColor() {
	singletonGenerate();
	return singleton->textColor;
}

void ofxSurfingDebug::setBackgroundColor(ofColor _color) {
	singletonGenerate();
	singleton->bgColor = _color;
}

void ofxSurfingDebug::setBackgroundAlpha(int _alpha) {
	singletonGenerate();
	ofColor c = singleton->bgColor;
	singleton->bgColor.set(c.r, c.g, c.b, _alpha);
}

ofColor ofxSurfingDebug::getBackgroundColor() {
	singletonGenerate();
	return singleton->bgColor;
}

//font
void ofxSurfingDebug::loadFont(string _path, float _size) {
	singletonGenerate();
	singleton->font.load(_path, _size);
	singleton->updateDrawPos();
}

//layout
void ofxSurfingDebug::setMarginBorders(int _margin) {
	singletonGenerate();
	singleton->margin = _margin;
}

void ofxSurfingDebug::setRounded(bool b, float size) {
	singletonGenerate();
	singleton->bRounded = b;
	singleton->roundedSize = size;
}

//TODO:
//must repair columns align by tabs
void ofxSurfingDebug::setTabbed(bool b, int num) {
	singletonGenerate();
	singleton->bTabbed = b;
	singleton->tabsNum = num;
}

void ofxSurfingDebug::setFloatResolution(int res) {
	singletonGenerate();
	singleton->fRes = res;
}
