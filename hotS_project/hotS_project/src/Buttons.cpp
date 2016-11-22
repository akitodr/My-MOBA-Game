#include "Buttons.h"

Button::Button(ofVec2f pos, char* notClicked, char* clicked, char* sound) { //construtor
	//da load nas parada
	//cria um botão com todos esses parâmetros
	position = pos;
	colorNotClicked.load(notClicked);
	colorClicked.load(clicked);
	note.load(sound);
	IsClicked = false;
}

bool Button::Check(ofVec2f posMouse) {//checa colisão do mouse com o botão
	return (posMouse.x > position.x && posMouse.x < (position.x + SIZEX)
		&& posMouse.y > position.y && posMouse.y < (position.y + SIZEY));

}

void Button::Play() {
	if (IsClicked) {
		//se tiver tocando não vai tocar de novo
		return;
	}
	//se não tiver tocando aí toca
	note.play();
	IsClicked = true;
	clickTime = 0;
}

void Button::Update(float secs) {
	if (IsClicked) {
		clickTime += secs;
		//a cada 4 segundos o botão "desliga"
		if (clickTime > 0.6) {
			IsClicked = false;
			note.stop();
		}
	}
}

void Button::Draw() {
	if (!IsClicked) {
		colorClicked.draw(position.x, position.y);
	}
	else {
		colorNotClicked.draw(position.x, position.y);
	}
}