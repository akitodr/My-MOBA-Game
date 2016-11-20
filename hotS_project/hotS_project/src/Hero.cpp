#include "Hero.h"
#include "Keyboard.h"

#define RANGE 100

//---------->INIT, UPDATE, DRAW
void Hero::init() {
	state = IDLE;
	life = 100;
	teleporting = false;
	animation.addFrame("img/li_ming.png");
	animation.addFrame("img/li_mingD.png");
	animation.addFrame("img/li_mingE.png");
	position.set(ofGetWidth() / 2, 1800);
}

void Hero::update(float secs) {

	switch (state)
	{
	case IDLE:
		speed = 0;
		//pensei até em tirar isso antes de dar o commit mas achei melhor deixar pra vc ver a que ponto cheguei nessa madrugada...
		if (teleporting == true)
			teleport();
		break;
	case WALKING:
		speed = 300;
		position += (direction * speed * secs);
		float distance = (position - destination).length();

		if (distance < 15) {
			stop();
			position = destination;
		}
		break;
	}
	animation.update(secs);
}

void Hero::draw(const ofVec2f& camera) {
	animation.draw(position - animation.getFrameSize() / 2 - camera);
}
//NÃO FUNCIONA ESSA BOSSSSSSSSSSSSSXXXXXXXXXXXXXXXXXXXXXTAAAAAAAAAAAAAAAAAAAAA SOCORR
//tentei fazer o método recebendo a posição do mouse, mas como vou chamar ele nos estados se o update do hero não recebe mousePos?
//CADE O SINGLETON DESSE MOUSE MEU DEUS? Ó_Ò
void Hero::teleport() {
	ofVec2f pathToMouse = mousePos_cpy - position;
	if (pathToMouse.length() > RANGE) {
		pathToMouse.normalize();
		pathToMouse *= RANGE;
	}
	destination = position + pathToMouse;
	position = destination;
}

const ofVec2f& Hero::setDestination(const ofVec2f& mousePos) {
	state = WALKING;
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
//CRIEI ESSA COISA LINDA AQUI PQ PRECISO PEGAR A POS DO MOUSE, mas que coisa mais feia e sem sentido credo
void Hero::getMousePos(const ofVec2f & mouse, const ofVec2f& camera) {
	teleporting = true;
	mousePos_cpy = mouse + camera;
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

ofRectangle Hero::bounds() {
	return ofRectangle(position, 15, 15);
}