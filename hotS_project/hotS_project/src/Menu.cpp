#include "Menu.h"
#include "Game.h"

void Menu::init() {

}

void Menu::update(float secs) {

}

void Menu::draw() {

}

Screen* Menu::nextScreen() {
	return new Game();
}