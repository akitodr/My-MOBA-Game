#pragma once

#include "ofMain.h"
#include "GameObject.h"

class Skill : public GameObject{
private:
	ofImage image;
	ofVec2f position;
	ofVec2f direction;
	int dano;
	
};