#pragma once

#include "Camera.h"
#include "Hero.h"
#include "GameManager.h"
#include "Teleport.h"
#include "Screen.h"

class Game : public Screen {
	private:
		Hero* hero;
		ofImage background;
		Camera camera;

	public:
		void init();
		void update(float secs, const MouseInfo& mouse);
		void draw();
		Screen* nextScreen();
};
