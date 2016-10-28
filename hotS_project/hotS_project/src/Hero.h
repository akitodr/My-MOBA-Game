#pragma once

#include "ofApp.h"

class Hero {

	private:
		ofVec2f position;
		ofVec2f direction;
		ofVec2f speed;
		int life;
		bool isWalking;

	public:
		void init();
		void update(float secs, float mapHeight);
		void draw(const ofVec2f& camera);
		void walk();
		void stop();
		
		ofVec2f getPosition();
		ofVec2f setDirection(const ofVec2f mousePos);
		ofVec2f getDirection() const;
};