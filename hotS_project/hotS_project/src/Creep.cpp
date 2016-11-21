#include "Creep.h"

Creep::Creep(const std::vector<ofVec2f>& a) : wayPoints(a) {}

void Creep::init() {
	life = 50;
	image.load("img/creepBlue.png");
	position.set(wayPoints[0]);
	current = 0;
}

void Creep::update(float secs, const ofVec2f& camera) {
    float speed = 200.0f;
	direction.set(wayPoints[current+1] - position);
    direction.normalize();
	position += direction * secs * speed;
	float distance = (wayPoints[current + 1] - position).length();
	if (current+1 != wayPoints.size()-1 && distance < 10) {
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
	return ofRectangle(position, image.getWidth(), image.getHeight());
}