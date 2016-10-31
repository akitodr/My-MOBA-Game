#include "Camera.h"

void Camera::update(const ofVec2f& hero, const ofVec2f& map) {
	SCREEN_CENTER.set(ofGetWidth() / 2, ofGetHeight() / 2);
	cameraPos.set(hero - SCREEN_CENTER);

	maxX = map.x - ofGetWidth();
	maxY = map.y - ofGetHeight();

	if (cameraPos.y >= maxY) {
		cameraPos.y = maxY;
	}

	if (cameraPos.x <= 0) {
		cameraPos.x = 0;
	}
	else if (cameraPos.x >= maxX) {
		cameraPos.x = maxX - 64;
	}
}

ofVec2f Camera::getPosition() const {
	return cameraPos;
}