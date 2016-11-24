#pragma once

#include "Camera.h"
#include "Hero.h"
#include "GameManager.h"
#include "Screen.h"
#include "Buttons.h"

class Game : public Screen {
private:
	Hero* hero;
	ofImage background;
	ofImage skillMenu;
	ofVec2f skillMenuPos;
	Camera camera;
	vector<Button*> buttons;
	vector <ofVec2f> wayPoints1;
	vector <ofVec2f> wayPoints2;

	float count;
public:
	void init();
	void update(float secs);
	void draw();
	Screen* nextScreen();
};