#include "Buttons.h"

Button::Button(const ofVec2f& pos, string clicked, string notClicked) 
	: position(pos) {
	colorNotClicked.load(notClicked);
	colorClicked.load(clicked);
	sound.load("audio/button.ogg");
	IsClicked = false;
	ClickFinished = false;
}

const bool Button::Check(const ofVec2f& posMouse) const {//checa colisão do mouse com o botão
	return (posMouse.x > position.x && posMouse.x < (position.x + colorClicked.getWidth())
		&& posMouse.y > position.y && posMouse.y < (position.y + colorClicked.getHeight()));

}
bool Button::SetClick() {
	IsClicked = true;
	sound.play();
	return IsClicked;
}

void Button::Update(float secs) {
	if (IsClicked) {
		clickTime += secs;
		//a cada 4 segundos o botão "desliga"
		if (clickTime > 0.6) {
			IsClicked = false;
			ClickFinished = true;
			sound.stop();
		}
	}
}

void Button::Draw(const ofVec2f& hero, const ofVec2f& camera) const {
	if (!IsClicked) {
		colorClicked.draw(position - camera);
	}
	else {
		colorNotClicked.draw(position - camera);
	}
}

bool Button::isClickFinished() const {
	return ClickFinished;
}

ofVec2f Button::GetPosition() {
	return position;
}

Button::~Button() {

}