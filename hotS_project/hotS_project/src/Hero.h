#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "animation.h"

enum HeroStates {
	IDLE, WALKING
};

class Hero : public GameObject {

private:
	ofVec2f position;
	ofVec2f direction;
	ofVec2f destination;
	Animation animation;
	HeroStates state;
	float speed;
	bool teleporting;
	int life;
	int mana;

	void walk();
	void stop();

public:
	void init();
	void update(float secs);
	void draw(const ofVec2f& camera);
	void collidedWith(GameObject* other);
	void teleport(const ofVec2f& mouse);
	bool isAlive() const;
	const void setMana(int manaCost);

	const ofVec2f& getPosition() const;
	const ofVec2f& setDestination(const ofVec2f& mousePos);
	const ofVec2f& getDestination() const;
	const ofVec2f& getDirection() const;
	
	ofRectangle bounds();
};