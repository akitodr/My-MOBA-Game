#include "Game.h"
#include "Menu.h"


void Game::init() {
	background.load("img/background.jpg");
	hero = new Hero();
	GAMEMANAGER.add(hero);
}

void Game::update(float secs, const MouseInfo& mouse) {
	float secs = ofGetLastFrameTime();
	hero->update(secs);
	camera.update(hero->getPosition(), ofVec2f(background.getWidth(), background.getHeight()));

	if (mouse.clicked == true) {
		mouse.pos.set += camera.getPosition();
		hero->setDestination(mouse.pos);
	}
	/*for (int i = 0; i < teleport.size(); i++) {
		if (teleport[i] != nullptr)
			teleport[i]->update(mousePos);
	}*/
}

void Game::draw() {
	background.draw(camera.getPosition());
	/*for (int i = 0; i < teleport.size(); i++) {
		if (hero.setVisibility() != true) {
			teleport[i]->draw(camera.getPosition());
		}
	}*/
	hero->draw(camera.getPosition());
}

Screen* Game::nextScreen() {
	return new Menu();
}