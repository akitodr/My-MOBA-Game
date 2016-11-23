#pragma once

#include "GameObject.h"


class Creep : public GameObject {
	private:
		ofVec2f position;
		ofVec2f direction;
		ofImage image;
		int life;
		int current;
		bool alive;
		int demage;

	public:
		Creep(const std::vector<ofVec2f>& a);
		const std::vector <ofVec2f>& wayPoints;
		void init();
		void update(float secs, const ofVec2f& camera);
		void draw(const ofVec2f& camera);
		void collidedWith(GameObject* other);
		bool isAlive() const;
		bool isShooting() const;
		ofRectangle bounds();
};