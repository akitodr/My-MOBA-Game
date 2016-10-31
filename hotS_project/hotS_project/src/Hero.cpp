#include "Hero.h"

void Hero::init() {
	life = 100;
	position.set(ofGetWidth() / 2, ofGetHeight() - 200);
}

void Hero::update(float secs, float mapWidth) {
	speed = 300;
	position += (getDirection() * speed * secs);
	float distance = (position - destination).length();


	if (distance < 15) {
		speed = 0;
		position = destination;
	}
}

void Hero::draw(const ofVec2f& camera) {
	ofDrawCircle(position - camera, 15);
}

void Hero::walk() {
	isWalking = true;
}

void Hero::stop() {
	isWalking = false;
}

ofVec2f Hero::getPosition() {
	return position;
}

ofVec2f Hero::setDestination(const ofVec2f& mousePos) {
	destination = mousePos;
	direction = (mousePos - position).normalize();
	return destination;
}

ofVec2f Hero::getDestination() const {
	return destination;
}

ofVec2f Hero::getDirection() const {
	return direction;
}