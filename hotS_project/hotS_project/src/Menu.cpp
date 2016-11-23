#include "Menu.h"
#include "Game.h"
#include "Credits.h"


void Menu::init() {
	next = this;
	background.load("img/menu.png");
	music.load("audio/menu.mp3");
	music.play();
	music.setLoop(true);
	posButtonPlay.set(337, 370);
	posButtonCredits.set(337, 480);
	posButtonExit.set(337, 590);
	
	buttons.push_back(new Button(posButtonPlay, "img/play.png", "img/play.png"));
	buttons.push_back(new Button(posButtonCredits, "img/credits.png", "img/credits.png"));
	buttons.push_back(new Button(posButtonExit, "img/exit.png", "img/exit.png"));
}

void Menu::update(float secs) {
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->Update(secs);
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1) && buttons[i]->Check(MOUSE.getPosition())) {
			buttons[i]->SetClick();
		}

		if (buttons[i]->isClickFinished()) {
			if (i == 0) {
				next = new Game();
			}
			else if (i == 1) {
				next = new Credits();
			}
			else if (i == 2) {
				return exit(0);
			}
		}
	}
}

void Menu::draw() {
	background.draw(0, 0, 1024, 768);
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->Draw(ofVec2f(), ofVec2f());
	}
}

Screen* Menu::nextScreen() {
	return next;
}