#include "Hero.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Orb.h"
#include "GameManager.h"

#define RANGE 100

//---------->INIT, UPDATE, DRAW
void Hero::init() {
	state = IDLE;
	life = 1232;
	mana = 500;
	teleporting = false;

	down.addFrame("img/li_ming.png");
	down.addFrame("img/li_mingD.png");
	down.addFrame("img/li_mingE.png");
	up.addFrame("img/li_ming_costas.png");
	up.addFrame("img/li_ming_costasD.png");
	up.addFrame("img/li_ming_costasE.png");
	up.setFrameTime(0.5f);
	down.setFrameTime(0.5f);

	position.set(ofGetWidth() / 2, 1800);
	coolDown = 1000;
	orbCoolDown = 1000;
}

void Hero::update(float secs, const ofVec2f& camera) {
	coolDown += secs;
	orbCoolDown += secs;

	switch (state)
	{
	case IDLE:
		speed = 0;
		//walking
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1) && !KEYS.isPressed('e') && !KEYS.isPressed('E')) {
			state = WALKING;
			setDestination(MOUSE.getPosition() + camera);
		}

		//orbe
		if (KEYS.isPressed('w') || KEYS.isPressed('W')) {
			state = IDLE;
			shootOrb(camera);
		}
		//teleporte
		if (KEYS.isPressed('e') || KEYS.isPressed('E')) {
			if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
				teleport(MOUSE.getPosition() + camera);
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

		if (ofGetMousePressed(OF_MOUSE_BUTTON_1) && !KEYS.isPressed('e') && !KEYS.isPressed('E')
			&& !KEYS.isPressed('w') && !KEYS.isPressed('W')) {
			setDestination(MOUSE.getPosition() + camera);
		}

		if (KEYS.isPressed('e') || KEYS.isPressed('E')) {
			if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
				teleport(MOUSE.getPosition() + camera);
		}

		if (KEYS.isPressed('w') || KEYS.isPressed('W')) {
			shootOrb(camera);
		}

		break;
	}
	getAnimation().update(secs);
}

void Hero::draw(const ofVec2f& camera) {
	getAnimation().draw(position - getAnimation().getFrameSize() / 2 - camera);
}

void Hero::teleport(const ofVec2f& mouse) {
	if (coolDown < 5) return;
	coolDown = 0;
	ofVec2f pathToMouse = mouse - position;
	if (pathToMouse.length() > RANGE) {
		pathToMouse.normalize();
		pathToMouse *= RANGE;
	}
	state = IDLE;
	destination = position + pathToMouse;
	position = destination;
}

void Hero::shootOrb(const ofVec2f & camera) {
	if (ofGetMousePressed(OF_MOUSE_BUTTON_1)) {
		if (orbCoolDown < 8) return;

		mana = mana;
		orbCoolDown = 0;
		ofVec2f direction = (MOUSE.getPosition() + camera - position).normalize();
		Orb* orb = new Orb(getHandPosition(), direction);
		GAMEMANAGER.add(orb);
	}
}

const ofVec2f& Hero::setDestination(const ofVec2f& mousePos) {
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

ofVec2f Hero::getHandPosition() const {
	return position - ofVec2f(24, 37);
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

Animation& Hero::getAnimation() {
	return (direction.y < 0 ? up : down);
}

ofRectangle Hero::bounds() {
	return ofRectangle(position, 15, 15);
}