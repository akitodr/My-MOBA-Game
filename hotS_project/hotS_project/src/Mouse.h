#pragma once

#include <map>
#include <vector>
#include "ofMain.h"

#define MOUSE Mouse::instance()

using namespace std;

class Mouse {
private:
	map<int, bool> pressed;
	Mouse() {}
public:
	static Mouse& instance();
	void onPress(int x, int y, int button);
	void onRelease(int x, int y, int button);
	ofVec2f getPosition() const;
	bool onPressing(int button);
};