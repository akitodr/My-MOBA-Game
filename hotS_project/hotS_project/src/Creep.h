#pragma once

#include "GameObject.h"


class Creep : public GameObject {
	private:
		ofVec2f position;
		ofVec2f direction;
		int life;

	public:
		Creep(const std::vector<ofVec2f>& a, const std::vector<ofVec2f>& b);
		const std::vector <ofVec2f>& waypoints1;
		const std::vector <ofVec2f>& waypoints2;
		void init();
		void update(float secs);
		void draw(const ofVec2f& camera);
		void collidedWith(GameObject* other);
		bool isAlive() const;
		bool isShooting() const;
		ofRectangle bounds();
};