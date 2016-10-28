#include "Hero.h"

void Hero::init() {
	life = 100;

}

void Hero::update(float secs, float mapHeight) {
	speed.set(0, 300);
	position.set(500,500/*getDirection() * speed * secs*/);

	if (position.y <= 0) {
		position.y = 0;
	}
	else if (position.y >= mapHeight - 1) {
		position.y = mapHeight - 1;
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

ofVec2f Hero::setDirection(const ofVec2f mousePos) {
	direction = mousePos - position;
	return direction;
}

ofVec2f Hero::getDirection() const {
	return direction;
}