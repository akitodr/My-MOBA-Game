#include "Mouse.h"

Mouse& Mouse::instance() {
	static Mouse mouse;
	return mouse;
}

void Mouse::onPress(int x, int y, int button) {
	pressed[button] = true;
}

void Mouse::onRelease(int x, int y, int button) {
	pressed[button] = false;
}

ofVec2f Mouse::getPosition() const {
	return ofVec2f(ofGetMouseX(), ofGetMouseY());
}

bool Mouse::onPressing(int button) {
	return pressed.find(button) != pressed.end() && pressed[button];
}