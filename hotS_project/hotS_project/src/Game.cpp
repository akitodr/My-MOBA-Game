#include "Game.h"
#include "Menu.h"


void Game::init() {
	background.load("img/nucleo.jpg");
	menu.load("img/menu.png");
	hero = new Hero();
	GAMEMANAGER.add(hero);
	wayPoints1.push_back(ofVec2f(background.getWidth()/2+85, 600));
	wayPoints1.push_back(ofVec2f(background.getWidth()/2+35, 700));
	wayPoints1.push_back(ofVec2f(background.getWidth()/2+85, 900));
	wayPoints1.push_back(ofVec2f(background.getWidth()/2+35, 1100));
	wayPoints1.push_back(ofVec2f(background.getWidth()/2+85, 1300));
	wayPoints1.push_back(ofVec2f(background.getWidth()/2+35, 1500));

	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 70, 600));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 20, 700));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 70, 900));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 20, 1100));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 70, 1300));
	wayPoints2.push_back(ofVec2f(background.getWidth() / 2 - 20, 1500));

	count = 0;

}

void Game::update(float secs, const MouseInfo& mouse, const KeyInfo& key) {
	count += secs;
	camera.update(hero->getPosition(), ofVec2f(background.getWidth(), background.getHeight()));
	
	keyIsClicked = key.clicked;
	if (mouse.clicked == true) {
		hero->setDestination(mouse.pos + camera.getPosition());
	}

	if (count > 10) {
		creep = new Creep(wayPoints1, wayPoints2);
		GAMEMANAGER.add(creep);
	}

	GAMEMANAGER.update(secs);
}

void Game::draw() {
	background.draw(-camera.getPosition());
	ofVec2f distance(menu.getWidth() / 2, 384);
	GAMEMANAGER.draw(camera.getPosition());
	if (!keyIsClicked) return;
	
		for (int i = 0; i < wayPoints1.size(); i++) {
	//	ofSetColor(200, 200, 0);
		ofDrawCircle(wayPoints1[i] - camera.getPosition(), 5);
		ofDrawCircle(wayPoints2[i] - camera.getPosition(), 5);
	}
}

Screen* Game::nextScreen() {
	return this;
}