#include "Creep.h"

Creep::Creep(const std::vector<ofVec2f>& a, const std::vector<ofVec2f>& b) : waypoints1(a), waypoints2(b) {}

void Creep::init() {
	life = 50;
}

void Creep::update(float secs) {
	position.set(waypoints1[0]);
}

void Creep::draw(const ofVec2f& camera) {
	ofSetColor(255, 0, 0);
	ofDrawCircle(position, 10);
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