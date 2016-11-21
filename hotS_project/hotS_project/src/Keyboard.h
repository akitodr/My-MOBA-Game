#pragma once

#include <map>
#define KEYS Keyboard::instance()

using namespace std;

class Keyboard
{
private:
	map <int, bool> pressed;
	Keyboard() {}
public:
	static Keyboard& instance();
	void onPress(int key);
	void onRelease(int key);
	bool isPressed(int key);
};

