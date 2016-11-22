#include "Menu.h"
#include "Game.h"


void Menu::init() {
	next = this;
	background.load("img/menu.png");
	music.load("audio/menu.mp3");
	music.play();
	music.setLoop(true);

	posButtonCredits.set(337, 590);
	posButtonExit.set(337, 480);
	posButtonPlay.set(337, 370);
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
		}
	}
}

void Menu::draw() {
	background.draw(0, 0, 1024, 768);
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->Draw();
	}
}

Screen* Menu::nextScreen() {
	return next;
}