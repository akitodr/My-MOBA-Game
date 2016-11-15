#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "animation.h"

class Hero : public GameObject {

private:
	ofVec2f position;
	ofVec2f direction;
	ofVec2f destination;
	Animation animation;
	float speed;
	int life;
	int mana;
	bool isWalking;
	bool isVisible;

public:
	void init();
	void update(float secs);
	void draw(const ofVec2f& camera);
	void collidedWith(GameObject* other);
	void teleport(float secs, const ofVec2f& mouse);
	void setInvisible();
	void setVisible();
	bool isAlive() const;
	bool isShooting() const;
	const void walk();
	const void stop();
	const void setMana(int& manaCost);

	const ofVec2f& getPosition() const;
	const ofVec2f& setDestination(const ofVec2f& mousePos);
	const ofVec2f& getDestination() const;
	const ofVec2f& getDirection() const;

	ofRectangle bounds();
};