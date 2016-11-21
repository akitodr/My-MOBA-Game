#pragma once

#include "GameObject.h"
#include <string>

class Sprite : public GameObject {
private:
	ofVec2f position;
	ofImage image;
public:
	Sprite(const ofVec2f& pos, std::string img);
	void init();
	bool isAlive() const;
	void draw(const ofVec2f& camera);
	void update(float secs, const ofVec2f& camera);
	ofRectangle bounds();
	void collidedWith(GameObject* other);

};