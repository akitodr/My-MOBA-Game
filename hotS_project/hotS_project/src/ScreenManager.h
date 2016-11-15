#pragma once

#include "Screen.h"

class ScreenManager {

private:
	Screen* current;
	MouseInfo mouse;
	KeyInfo key;

public:
	void init(Screen* first);

	void update();
	void draw();

	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void keyPressed(int key, char letter);
	void keyReleased(int key, char letter);
};
