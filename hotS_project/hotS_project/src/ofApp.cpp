#include "ofApp.h"
#include "TileMap.h"
#include "Camera.h"
#include "Hero.h"
#include "Teleport.h"

#include <vector>

TileMap tileMap;
Camera camera;
Hero hero;
vector <Teleport*> teleport;


//--------------------------------------------------------------
void ofApp::setup(){
	tileMap.init();
	hero.init();
}

//--------------------------------------------------------------
void ofApp::update(){
	float secs = ofGetLastFrameTime();
	hero.update(secs, tileMap.getMapWidth());
	camera.update(hero.getPosition(), ofVec2f(tileMap.getMapWidth(), tileMap.getMapHeight()));
	
	for (int i = 0; i < teleport.size(); i++) {
		if (teleport[i] != nullptr)
			teleport[i]->update(mousePos);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	tileMap.draw(camera.getPosition());

	for (int i = 0; i < teleport.size(); i++) {
		if (hero.setVisibility() != true) {
			teleport[i]->draw(camera.getPosition());
		}
	} 
	hero.draw(camera.getPosition());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'E' || key == 'e') {
		Teleport* tele = new Teleport();
		tele->init(hero);
		teleport.push_back(tele);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mousePos.set(x, y);
	mousePos += camera.getPosition();
	hero.setDestination(mousePos);
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
