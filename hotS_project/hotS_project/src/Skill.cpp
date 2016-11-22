//
//  Skill.cpp
//  hots
//
//  Created by BEPID on 11/21/16.
//
//

#include "Skill.h"

Skill::Skill(const ofVec2f& pos, const ofVec2f direction, int dano)
: position(pos), direction(direction), dano(dano) {}


void Skill::draw(const ofVec2f& camera){
    animation.draw(position - camera);
}

void Skill::update(float secs, const ofVec2f& camera){
    animation.update(secs);
}

ofRectangle Skill::bounds(){
    return ofRectangle(position, animation.getFrameSize().x, animation.getFrameSize().y);
}

const ofVec2f& Skill::getPosition() const{
    return position;
}

const ofVec2f& Skill::getDirection() const{
    return direction;
}