#include "ScreenManager.h"

void ScreenManager::init(Screen* first) {
	current = first;
	current->init();
}

void ScreenManager::update() {
	Screen* next = current->nextScreen();
	if (next != current) {
		next->init();
		delete current;
		current = next;
	}
	current->update(ofGetLastFrameTime(), mouse, key);
}

void ScreenManager::draw() {
	current->draw();
}


void ScreenManager::mousePressed(int x, int y, int button) {
	mouse.pos.set(x, y);
	mouse.clicked = true;
}

void ScreenManager::mouseReleased(int x, int y, int button) {
	mouse.clicked = false;
}

void ScreenManager::keyPressed(int key, char letter) {
	this->key.clicked = true;
	this->key.letter = letter;
}

void ScreenManager::keyReleased(int key, char letter) {
	this->key.clicked = false;
	this->key.letter = letter;
}