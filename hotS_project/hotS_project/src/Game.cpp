#include "Game.h"
#include "Menu.h"
#include "Sprite.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Tower.h"
#include "Creep.h"


void Game::init() {
	ofSetColor(255, 255, 255);
	background.load("img/nucleo.jpg");
	skillMenu.load("img/skill.png");
	hero = new Hero();
	GAMEMANAGER.add(new Tower(ofVec2f(background.getWidth() / 2 - 120, 540), 
		"img/torre_vermelha.png", "img/torre_vermelha_2.png", "img/broke_red.png"));
	GAMEMANAGER.add(new Tower(ofVec2f(background.getWidth() / 2 + 55, 540), 
		"img/torre_vermelha_1.png", "img/torre_vermelha_3.png", "img/broke_red.png"));

	GAMEMANAGER.add(new Tower(ofVec2f(background.getWidth() / 2 - 115, 1380), 
		"img/torre_azul.png", "img/torre_azul_2.png", "img/broke_red.png"));
	GAMEMANAGER.add(new Tower(ofVec2f(background.getWidth() / 2 + 50, 1380), 
		"img/torre_azul_1.png", "img/torre_azul_3.png", "img/broke_red.png"));
	
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
	skillMenuPos.set(327, (hero->getPosition().y + 200 - camera.getPosition().y));
	/*buttons.push_back(new Button(hero->getHandPosition(), "img/projetil_button.png", "img/projetil_clicked.png"));
	buttons.push_back(new Button((skillMenuPos + ofVec2f(111, 20)), "img/orbe_button.png", "img/orbe_clicked.png"));
	buttons.push_back(new Button((skillMenuPos + ofVec2f(156, 20)), "img/teleport_button.png", "img/teleport_clicked.png"));
	buttons.push_back(new Button((skillMenuPos + ofVec2f(201, 20)), "img/ult_button.png", "img/ult_clicked.png"));*/
		count = 0;
}

void Game::update(float secs) {
	count += secs;
	camera.update(hero->getPosition(), ofVec2f(background.getWidth(), background.getHeight()));

	if (skillMenuPos.y > ofGetHeight()) {
		skillMenuPos.y = ofGetHeight() - skillMenu.getHeight();
	}

		/*if (KEYS.isPressed('q') || KEYS.isPressed('Q'))
			buttons[0]->SetClick();
		else if (KEYS.isPressed('w') || KEYS.isPressed('W'))
			buttons[1]->SetClick();
		else if (KEYS.isPressed('e') || KEYS.isPressed('E'))
			buttons[2]->SetClick();
		else if (KEYS.isPressed('r') || KEYS.isPressed('R'))
			buttons[3]->SetClick();
*/
		/*for (int i = 0; i < buttons.size() -1; i++) {
			buttons[i]->Update(secs);
		}*/


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
	skillMenu.draw(skillMenuPos);
	/*for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->Draw(skillMenuPos, camera.getPosition());
	}*/
}

Screen* Game::nextScreen() {
	return this;
}