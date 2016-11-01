#pragma once

#include "ofMain.h"

class Hero {

	private:
		ofVec2f position;
		ofVec2f direction;
		ofVec2f destination;
		float speed;
		int life;
		int mana;
		bool isWalking;
		bool isVisible = true;

	public:
		void init();
		void update(float secs, float mapWidth);
		void draw(const ofVec2f& camera) const;
		const void walk();
		const void stop();
		const void setMana(int& manaCost);
		const bool setVisibility();
		
		const ofVec2f getPosition() const;
		const ofVec2f setDestination(const ofVec2f& mousePos);
		const ofVec2f getDestination() const;
		const ofVec2f getDirection() const;
};