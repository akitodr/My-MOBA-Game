#include "Teleport.h"

void Teleport::init(Hero& hero) {
	hero.setVisibility();
	hero.setMana(manaCost);
}

void Teleport::update(ofVec2f& mousePos) {

	angle = mousePos.x * PI / 180; //convertendo posi��o pra x pra radianos
	rage.set(angle, 30); //criando vetor com o angulo da posi��o x do mouse e raio 30 pra posi��o y
}

void Teleport::draw(const ofVec2f& camera) const {
		ofDrawCircle(rage - camera, 15);
}

const bool Teleport::mouseIsClicked() {
	return isClicked;
}
