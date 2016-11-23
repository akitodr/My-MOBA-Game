#pragma once

#include "GameObject.h"
#include "animation.h"
#include <string>

enum TowerState {
	ATTACKING, NO_BOMBS, DEAD
};

class Tower : public GameObject {
private:
	ofVec2f position;
	Animation animation;
	ofImage image;
	TowerState state;
	string image1, image2, broken;
	int hp;
	int demage;
public:
	Tower(const ofVec2f& position, const string& frame1, const string& frame2, const string& img);
	void init();
	void update(float secs, const ofVec2f& camera);
	void draw(const ofVec2f& camera);
	void shoot();
	void collidedWith(GameObject* other);
	bool isAlive() const;
	ofRectangle bounds();
};