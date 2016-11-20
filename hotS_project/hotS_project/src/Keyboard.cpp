#include "Keyboard.h"


Keyboard& Keyboard::instance() {
	static Keyboard key;
	return key;
}

void Keyboard::onPress(int key) {
	pressed[key] = true;
}

void Keyboard::onRelease(int key) {
	pressed[key] = false;
}

bool Keyboard::onPressing(int key) {
	if(pressed.find(key) == pressed.end()) return false;
	return pressed[key];
}
