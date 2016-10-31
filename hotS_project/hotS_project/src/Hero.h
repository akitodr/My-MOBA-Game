#pragma once

#include "ofApp.h"

class Hero {

	private:
		ofVec2f position;
		ofVec2f direction;
		ofVec2f destination;
		float speed;
		int life;
		bool isWalking;

	public:
		void init();
		void update(float secs, float mapWidth);
		void draw(const ofVec2f& camera);
		void walk();
		void stop();
		
		ofVec2f getPosition();
		ofVec2f setDestination(const ofVec2f& mousePos);
		ofVec2f getDestination() const;
		ofVec2f getDirection() const;
};