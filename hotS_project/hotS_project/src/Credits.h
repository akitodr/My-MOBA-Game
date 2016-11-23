#pragma once

#include "ofMain.h"
#include "Screen.h"

class Credits : public Screen {
private:
	ofImage image;
public:
	void init();
	void update(float secs);
	void draw();
	Screen* nextScreen();
};