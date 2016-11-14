#pragma once

#include "ofMain.h"

class Camera {

	private:
		ofVec2f SCREEN_CENTER;
		ofVec2f cameraPos;

	public:
		void update(const ofVec2f& hero, const ofVec2f& background);
		const ofVec2f& getPosition() const;
};
