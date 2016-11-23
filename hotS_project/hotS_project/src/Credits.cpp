#include "Credits.h"
#include "Menu.h"
#include "Events.h"

void Credits::init() {
	image.load("img/creditos.png");
}

void Credits::update(float secs){
	if (ofGetMousePressed(OF_MOUSE_BUTTON_1)) {
		next = new Menu(); 
	}
}

void Credits::draw() {
	image.draw(0, 0, 1024, 768);
}

Screen* Credits::nextScreen() {
	return next;
}
