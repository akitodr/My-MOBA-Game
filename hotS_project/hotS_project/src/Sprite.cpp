//
//  Sprite.cpp
//  colors
//
//  Created by BEPID on 11/11/16.
//
//

#include "Sprite.h"

Sprite::Sprite(const ofVec2f& pos, std::string img)
	: position(pos) {
	image.load(img);
}

void Sprite::init() {

}

bool Sprite::isAlive() const {
	return true;
}

void Sprite::draw(const ofVec2f& camera) {
	image.draw(position - camera);
}

void Sprite::update(float secs) {

}

ofRectangle Sprite::bounds() {
	return ofRectangle(position, image.getWidth(), image.getHeight());
}

void Sprite::collidedWith(GameObject* other) {

}