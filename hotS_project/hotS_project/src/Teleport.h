#pragma once

#include "ofMain.h"
#include "Hero.h"

class Teleport {
	private:
		ofVec2f rage;
		
		float angle;
		int manaCost = 30;
		int load = 5;
		bool isClicked;

	public:
		void init(Hero& hero);
		void update(ofVec2f& mousePos);
		void draw(const ofVec2f& camera) const;
		const bool mouseIsClicked();
};