#pragma once
#include "ofMain.h"

//struct MouseInfo {
//	ofVec2f pos;
//	ofVec2f pressedPos;
//	bool clicked;
//};

class Screen {
public:
	virtual void init() = 0;
	virtual void update(float secs) = 0;
	virtual void draw() = 0;
	virtual Screen* nextScreen() = 0;

};
