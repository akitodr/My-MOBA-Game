#pragma once

#include "Screen.h"

class Menu : public Screen {
	private:
		ofImage background;

	public:
		void init();
		void update(float secs);
		void draw();
		Screen* nextScreen();
};
