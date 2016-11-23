//
//  Orb.cpp
//  hots
//
//  Created by BEPID on 11/21/16.
//
//

#include "Orb.h"
#include "Creep.h"

#define ORB_RANGE 100

Orb::Orb(const ofVec2f& pos, const ofVec2f direction)
: Skill(pos, direction, 50), initialPos(pos) {}

void Orb::init(){
    animation.addFrame("img/orb.png");
	animation.addFrame("img/orb2.png");
	animation.addFrame("img/orb3.png");
	animation.setFrameTime(0.25f);
	demage = 450;
	increase = 150;
	alive = true;
}

bool Orb::isAlive() const{
	if (!alive) return false;
    float distance = (position - initialPos).length();
    return distance < ORB_RANGE;
}

void Orb::update(float secs, const ofVec2f& camera){
    Skill::update(secs, camera);
    float speed = 150;
    position += direction * secs * speed;	  

	demage += increase * secs * 2;
}

void Orb::collidedWith(GameObject* other){
	Creep* creep = dynamic_cast<Creep*>(other);
	if (creep != nullptr) {
		alive = false;
	}
}

int Orb::getDemage() const {
	cout << demage << endl;
	return demage;
}
