#pragma once

#include "Screen.h"

class Menu : public Screen {
	private:
		ofImage background;

	public:
		void init();
		void update(float secs, const MouseInfo& mouse);
		void draw();
		Screen* nextScreen();
};
