#include "Hero.h"
#include "Keyboard.h"
#include "Mouse.h"

#define RANGE 100

//---------->INIT, UPDATE, DRAW
void Hero::init() {
	state = IDLE;
	life = 100;
	teleporting = false;
	animation.addFrame("img/li_ming.png");
	animation.addFrame("img/li_mingD.png");
	animation.addFrame("img/li_mingE.png");
	position.set(ofGetWidth() / 2, 1800);
}

void Hero::update(float secs) {

	switch (state)
	{
	case IDLE:
		speed = 0;
		if (KEYS.onPressing('e') || KEYS.onPressing('E')) {
			if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
				teleport(BUTTON.getPosition());
		}
		break;
	case WALKING:
		speed = 300;
		position += (direction * speed * secs);
		float distance = (position - destination).length();

		if (distance < 15) {
			stop();
			position = destination;
		}

		if (KEYS.onPressing('e') || KEYS.onPressing('E')) {
			if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
				teleport(BUTTON.getPosition());
		}
		break;
	}
	animation.update(secs);
}

void Hero::draw(const ofVec2f& camera) {
	animation.draw(position - animation.getFrameSize() / 2 - camera);
}

void Hero::teleport(const ofVec2f& mouse) {
	ofVec2f pathToMouse = mouse - position;
	if (pathToMouse.length() > RANGE) {
		pathToMouse.normalize();
		pathToMouse *= RANGE;
	}
	destination = position + pathToMouse;
	position = destination;
}

const ofVec2f& Hero::setDestination(const ofVec2f& mousePos) {
	state = WALKING;
	destination = mousePos;
	direction = (mousePos - position).normalize();
	return destination;
}

const void Hero::setMana(int manaCost) {
	mana = mana - manaCost;
}

//------------->GETTER
const ofVec2f& Hero::getPosition() const {
	return position;
}

const ofVec2f& Hero::getDestination() const {
	return destination;
}

const ofVec2f& Hero::getDirection() const {
	return direction;
}

//-------------->USELESS
void Hero::walk() {
	state = WALKING;
}

void Hero::stop() {
	if (state != WALKING) return;
	state = IDLE;
}

void Hero::collidedWith(GameObject* other) {

}

bool Hero::isAlive() const {
	return true;
}

ofRectangle Hero::bounds() {
	return ofRectangle(position, 15, 15);
}