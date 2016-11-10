#pragma once

#include "GameObject.h"

class Creep : public GameObject {
	private:
		ofVec2f position;
		ofVec2f direction;
		ofVec2f destination;
		vector <ofVec2f> wayPoints;
		int life;

		
	public:
		void init();
		void update(float secs);
		void draw(const ofVec2f& camera);
		void collidedWith(GameObject* other);
		bool isAlive() const;
		bool isShooting() const;
		ofRectangle bounds();
};