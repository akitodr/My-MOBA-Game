#include "Hero.h"

//---------->INIT, UPDATE, DRAW
void Hero::init() {
	life = 100;
	isVisible = true;
	animation.addFrame("img/li_ming_costas.png");
	animation.addFrame("img/li_ming_costasD.png");
	animation.addFrame("img/li_ming_costasE.png");
	position.set(ofGetWidth() / 2, 1800);
}

void Hero::update(float secs) {
	speed = 300;
	position += (direction * speed * secs);
	float distance = (position - destination).length();

	if (distance < 15) {
		speed = 0;
		position = destination;
	}
	animation.update(secs);
}

void Hero::draw(const ofVec2f& camera) {
	if (!isVisible) return;
	animation.draw(position - animation.getFrameSize()/2 - camera);
}

void Hero::setInvisible() {
	isVisible = false;
}

void Hero::setVisible() {
	isVisible = true;
}

void Hero::teleport(float secs, const ofVec2f& mouse) {
	float _secs = 0;
	_secs += secs;
	if (_secs > 0.5)
		position = mouse;
		isVisible = true;
}

const ofVec2f& Hero::setDestination(const ofVec2f& mousePos) {
	destination = mousePos;
	direction = (mousePos - position).normalize();
	return destination;
}

const void Hero::setMana(int& manaCost) {
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