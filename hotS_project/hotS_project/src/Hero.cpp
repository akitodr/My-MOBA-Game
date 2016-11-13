#include "Hero.h"

//---------->INIT, UPDATE, DRAW
void Hero::init() {
	life = 100;
	position.set(ofGetWidth() / 2, ofGetHeight() - 200);
}

void Hero::update(float secs) {
	speed = 300;
	position += (getDirection() * speed * secs);
	float distance = (position - destination).length();

	if (distance < 15) {
		speed = 0;
		position = destination;
	}
}

void Hero::draw(const ofVec2f& camera) {
	//if (isVisible)
		ofDrawCircle(position - camera, 15);
}

//-------------> SETTER
//const bool Hero::setVisibility() {
//	isVisible = !isVisible;
//	return isVisible;
//}

const ofVec2f Hero::setDestination(const ofVec2f& mousePos) {
	destination = mousePos;
	direction = (mousePos - position).normalize();
	return destination;
}

const void Hero::setMana(int& manaCost) {
	mana = mana - manaCost;
}

//------------->GETTER
const ofVec2f Hero::getPosition() const {
	return position;
}

const ofVec2f Hero::getDestination() const {
	return destination;
}

const ofVec2f Hero::getDirection() const {
	return direction;
}

//-------------->USELESS
const void Hero::walk() {
	isWalking = true;
}

const void Hero::stop() {
	isWalking = false;
}

void Hero::collidedWith(GameObject* other) {
	
}

bool Hero::isAlive() const {
	return true;
}

bool Hero::isShooting() const {
	return false;
}

ofRectangle Hero::bounds() {
	return ofRectangle(position, 15, 15);
}