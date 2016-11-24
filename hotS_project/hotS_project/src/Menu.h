#pragma once

#include "Screen.h"
#include "Buttons.h"

class Menu : public Screen {
	private:
		ofImage background;
		vector<Button*> buttons;
		Screen* next;
		ofSoundPlayer music;
		ofVec2f posButtonCredits;
		ofVec2f posButtonExit;
		ofVec2f posButtonPlay;
	public:
		void init();
		void update(float secs);
		void draw();
		Screen* nextScreen();
		virtual ~Menu();
};
