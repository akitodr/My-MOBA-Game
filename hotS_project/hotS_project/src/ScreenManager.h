#pragma once

#include "Screen.h"

class ScreenManager {

private:
	Screen* current;
	MouseInfo mouse;

public:
	void init(Screen* first);

	void update();
	void draw();

	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void keyPressed(int key);
};
