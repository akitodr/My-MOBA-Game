#include "Camera.h"

void Camera::update(const ofVec2f& hero, const ofVec2f& map) {
	SCREEN_CENTER.set(ofGetWidth() / 2, ofGetHeight() / 2);
	cameraPos.set(hero - SCREEN_CENTER);

	maxX = map.x - ofGetWidth();
	maxY = map.y - ofGetHeight();

	if (cameraPos.y <= 0) {
		cameraPos.y = 0;
	}
	else if (cameraPos.y >= maxY) {
		cameraPos.y = maxY;
	}
}

ofVec2f Camera::getPosition() const {
	return cameraPos;
}