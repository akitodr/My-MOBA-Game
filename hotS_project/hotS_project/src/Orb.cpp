//
//  Orb.cpp
//  hots
//
//  Created by BEPID on 11/21/16.
//
//

#include "Orb.h"

#define ORB_RANGE 100

Orb::Orb(const ofVec2f& pos, const ofVec2f direction)
: Skill(pos, direction, 50), initialPos(pos) {}

void Orb::init(){
    animation.addFrame("img/orb.png");
	animation.addFrame("img/orb2.png");
	animation.addFrame("img/orb3.png");
	animation.setFrameTime(0.25f);
}

bool Orb::isAlive() const{
    float distance = (position - initialPos).length();
    return distance < ORB_RANGE;
}

void Orb::update(float secs, const ofVec2f& camera){
    Skill::update(secs, camera);
    float speed = 150;
    position += direction * secs * speed;
    
}

void Orb::collidedWith(GameObject* other){
    
}
