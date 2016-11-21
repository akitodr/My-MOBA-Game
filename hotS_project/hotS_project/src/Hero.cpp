#include "Hero.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Orb.h"
#include "GameManager.h"

#define RANGE 100

//---------->INIT, UPDATE, DRAW
void Hero::init() {
	state = IDLE;
	life = 100;
	teleporting = false;
    
	down.addFrame("img/li_ming.png");
	down.addFrame("img/li_mingD.png");
	down.addFrame("img/li_mingE.png");
    up.addFrame("img/li_ming_costas.png");
    up.addFrame("img/li_ming_costasD.png");
    up.addFrame("img/li_ming_costasE.png");
    
	position.set(ofGetWidth() / 2, 1800);
    coolDown = 1000;
}

void Hero::update(float secs, const ofVec2f& camera) {
    coolDown += secs;
    
	switch (state)
	{
	case IDLE:
		speed = 0;
            
            if (KEYS.isPressed('w') || KEYS.isPressed('W')) {
                if (ofGetMousePressed(OF_MOUSE_BUTTON_1)){
                    ofVec2f direction = (BUTTON.getPosition() + camera - position).normalize();
                    Orb* orb = new Orb(position, direction);
                    GAMEMANAGER.add(orb);
                }
            }
            
            
        if (ofGetMousePressed(OF_MOUSE_BUTTON_1) && !KEYS.isPressed('e') && !KEYS.isPressed('E')) {
                state = WALKING;
                setDestination(BUTTON.getPosition() + camera);
            }
            
		if (KEYS.isPressed('e') || KEYS.isPressed('E')) {
			if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
				teleport(BUTTON.getPosition() + camera);
		}
            
        
            
		break;
	case WALKING:
		speed = 300;
		position += (direction * speed * secs);
		float distance = (position - destination).length();

		if (distance < 15) {
			stop();
			position = destination;
		}
            
        if (ofGetMousePressed(OF_MOUSE_BUTTON_1) && !KEYS.isPressed('e') && !KEYS.isPressed('E')) {
            setDestination(BUTTON.getPosition() + camera);
        }

		if (KEYS.isPressed('e') || KEYS.isPressed('E')) {
			if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
				teleport(BUTTON.getPosition() + camera);
		}
            
        if (KEYS.isPressed('w') || KEYS.isPressed('W')) {
            if (ofGetMousePressed(OF_MOUSE_BUTTON_1)){
                ofVec2f direction = (BUTTON.getPosition() + camera - position).normalize();
                Orb* orb = new Orb(position, direction);
                GAMEMANAGER.add(orb);
            }
        }

		break;
	}
	getAnimation().update(secs);
}

void Hero::draw(const ofVec2f& camera) {
	getAnimation().draw(position - getAnimation().getFrameSize() / 2 - camera);
}

void Hero::teleport(const ofVec2f& mouse) {
    if(coolDown < 5) return;
    coolDown = 0;
	ofVec2f pathToMouse = mouse - position;
	if (pathToMouse.length() > RANGE) {
		pathToMouse.normalize();
		pathToMouse *= RANGE;
	}
    state = IDLE;
	destination = position + pathToMouse;
	position = destination;
}

const ofVec2f& Hero::setDestination(const ofVec2f& mousePos) {
	destination = mousePos;
	direction = (mousePos - position).normalize();
	return destination;
}

const void Hero::setMana(int manaCost) {
	mana = mana - manaCost;
}

//------------->GETTER
const ofVec2f& Hero::getPosition() const {
	return position;
}

const ofVec2f& Hero::getDestination() const {
	return destination;
}

const ofVec2f& Hero::getDirection() const {
	return direction;
}

//-------------->USELESS
void Hero::walk() {
	state = WALKING;
}

void Hero::stop() {
	if (state != WALKING) return;
	state = IDLE;
}

void Hero::collidedWith(GameObject* other) {

}

bool Hero::isAlive() const {
	return true;
}

Animation& Hero::getAnimation() {
    return (direction.y < 0 ? up : down);
}

ofRectangle Hero::bounds() {
	return ofRectangle(position, 15, 15);
}