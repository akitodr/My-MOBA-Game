#include "Tower.h"
#include "Orb.h"
#include "Creep.h"


#define RANGE 50

Tower::Tower(const ofVec2f & position, const string& frame1, const string& frame2, const string& img)
	: position(position), image1(frame1), image2(frame2), broken(img) {}

void Tower::init() {
	demage = 100;
	hp = 3350;
	image.load(broken);
	animation.addFrame(image1);
	animation.addFrame(image2);
	animation.setFrameTime(0.5);
}

void Tower::update(float secs, const ofVec2f& camera) {
	switch (state)
	{
	case ATTACKING:
		animation.update(secs);
		break;
	case NO_BOMBS:
		break;
	case DEAD:
		break;
	default:
		break;
	}
}

void Tower::draw(const ofVec2f & camera) {
	animation.draw(position - camera);
	if (state == NO_BOMBS) {
		image.draw(position - camera, image.getWidth()/2, image.getHeight()/2);
	}
}

void Tower::shoot() {

}

void Tower::collidedWith(GameObject * other) {
	Orb* orb = dynamic_cast<Orb*>(other);
	if (orb != nullptr && orb->isAlive()) {
		hp -= orb->getDemage();
	}
}

bool Tower::isAlive() const {
	return true;
}

ofRectangle Tower::bounds() {
	return ofRectangle(position, animation.getFrameSize().x, animation.getFrameSize().y);
}
