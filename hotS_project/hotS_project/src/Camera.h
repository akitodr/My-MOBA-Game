#pragma once

#include "ofApp.h"

class Camera {

	private:
		ofVec2f SCREEN_CENTER;
		ofVec2f cameraPos;

		float maxX, maxY;

	public:
		void update(const ofVec2f& hero, const ofVec2f& map);

		ofVec2f getPosition() const;
};
