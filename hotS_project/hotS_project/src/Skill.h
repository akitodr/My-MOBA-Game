#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "animation.h"

class Skill : public GameObject{
protected:
    Animation animation;
	ofVec2f position;
	ofVec2f direction;
	int dano;
public:
    Skill(const ofVec2f& pos, const ofVec2f direction, int dano);
    void draw(const ofVec2f& camera);
    void update(float secs, const ofVec2f& camera);
    ofRectangle bounds();
    
    const ofVec2f& getPosition() const;
    const ofVec2f& getDirection() const;
};