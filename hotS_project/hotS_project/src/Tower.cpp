#include "Tower.h"

#define RANGE 50

Tower::Tower(const ofVec2f & position) : position(position) {}

void Tower::init() {
	state = IDLE;
	blue[0].load("img/torre_azul.png");
	blue[1].load("img/torre_azul_1.png");
	red[0].load("img/torre_vermelha.png");
	red[1].load("img/torre_vermelha_1.png");
}

void Tower::update(float secs) {
	switch (state)
	{
	case IDLE:
		break;
	case ATTACKING:
		break;
	}
}

void Tower::draw(const ofVec2f & camera) {

}

void Tower::shoot() {

}

void Tower::collidedWith(GameObject * other) {

}

bool Tower::isAlive() const {
	return true;
}

ofRectangle Tower::bounds() {
	return ofRectangle(position, blue[0].getWidth(), blue[0].getHeight());
}
