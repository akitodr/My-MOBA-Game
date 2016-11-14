#include "Creep.h"

Creep::Creep(const std::vector<ofVec2f>& a) : wayPoints(a) {}

void Creep::init() {
	life = 50;
	image.load("img/creepBlue.png");
	position.set(wayPoints[0]);
}

void Creep::update(float secs) {
	current = 0;
	direction.set(wayPoints[current+1] - position);
	position += direction * secs;
	if (position.x < direction.x && position.y < direction.y) {
		position.set(wayPoints[current+1]);
		current += 1;
	}	
}

void Creep::draw(const ofVec2f& camera) {
	ofVec2f center(image.getWidth() / 2, image.getHeight() / 2);
	image.draw(position - camera - center);
}

void Creep::collidedWith(GameObject* other) {

}

bool Creep::isAlive() const {
	return true;
}

bool Creep::isShooting() const {
	return true;
}

ofRectangle Creep::bounds() {
	return ofRectangle(position, 5, 5);
}