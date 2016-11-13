#pragma once

#include "Camera.h"
#include "Hero.h"
#include "GameManager.h"
#include "Teleport.h"
#include "Screen.h"
#include "Creep.h"

class Game : public Screen {
	private:
		Hero* hero;
		Creep* creep;
		ofImage background;
		ofImage menu;
		Camera camera;
		vector <ofVec2f> wayPoints1;
		vector <ofVec2f> wayPoints2;

		bool keyIsClicked;
		int count;

	public:
		void init();
		void update(float secs, const MouseInfo& mouse, const KeyInfo& key);
		void draw();
		Screen* nextScreen();
};
