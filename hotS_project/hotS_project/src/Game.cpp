#include "Game.h"
#include "Menu.h"
#include "Sprite.h"
#include "Keyboard.h"
#include "Mouse.h"


void Game::init() {
	background.load("img/nucleo.jpg");
	hero = new Hero();
	GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() / 2 - 120, 540), "img/torre_vermelha.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() / 2 + 55, 540), "img/torre_vermelha_1.png"));

	GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() / 2 - 115, 1380), "img/torre_azul.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() / 2 + 50, 1380), "img/torre_azul_1.png"));
	
	wayPoints1.push_back(ofVec2f(background.getWidth() / 2 + 35, 1500));
	wayPoints1.push_back(ofVec2f(background.getWidth() / 2 + 85, 1300));
	wayPoints1.push_back(ofVec2f(background.getWidth() / 2 + 35, 1100));
	wayPoints1.push_back(ofVec2f(background.getWidth() / 2 + 85, 900));
	wayPoints1.push_back(ofVec2f(background.getWidth() / 2 + 35, 700));
	wayPoints1.push_back(ofVec2f(background.getWidth() / 2 + 85, 600));

	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 20, 1500));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 70, 1300));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 20, 1100));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 70, 900));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 20, 700));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 70, 600));

	GAMEMANAGER.add(hero);

	count = 0;
}

void Game::update(float secs) {
	count += secs;
	camera.update(hero->getPosition(), ofVec2f(background.getWidth(), background.getHeight()));

	if (count > 15) {
		int random = rand() % 2;
		Creep* creep = new Creep(random == 0 ? wayPoints1 : wayPoints2);
		GAMEMANAGER.add(creep);
		count = 0;
	}


	GAMEMANAGER.update(secs, camera.getPosition());
}

void Game::draw() {
	background.draw(-camera.getPosition());

	GAMEMANAGER.draw(camera.getPosition());
	if (KEYS.isPressed('i') || KEYS.isPressed('I')) {
		for (int i = 0; i < wayPoints1.size(); i++) {
			ofDrawCircle(wayPoints1[i] - camera.getPosition(), 3);
			ofDrawCircle(wayPoints2[i] - camera.getPosition(), 3);
		}
	}
}

Screen* Game::nextScreen() {
	return this;
}