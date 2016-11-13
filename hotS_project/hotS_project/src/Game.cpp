#include "Game.h"
#include "Menu.h"


void Game::init() {
	background.load("img/background.jpg");
	hero = new Hero();
	GAMEMANAGER.add(hero);
}

void Game::update(float secs, const MouseInfo& mouse) {
	hero->update(secs);
	camera.update(hero->getPosition(), ofVec2f(background.getWidth(), background.getHeight()));

	if (mouse.clicked == true) {
//		mouse.pos.set += camera.getPosition();
		hero->setDestination(mouse.pos);
	}
}

void Game::draw() {
	background.draw(-camera.getPosition());
	hero->draw(camera.getPosition());
}

Screen* Game::nextScreen() {
	return new Menu();
}