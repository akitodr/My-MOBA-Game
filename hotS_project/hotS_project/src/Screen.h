#pragma once
#include "ofMain.h"

struct MouseInfo {
	ofVec2f pos;
	ofVec2f pressedPos;
	bool clicked;
};

struct KeyInfo {
	bool clicked;
	char letter;
};

class Screen {
public:
	virtual void init() = 0;
	virtual void update(float secs, const MouseInfo& mouse, const KeyInfo& key) = 0;
	virtual void draw() = 0;
	virtual Screen* nextScreen() = 0;

};
