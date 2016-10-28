#include "ofApp.h"
#include "TileMap.h"
#include "Camera.h"
#include "Hero.h"

TileMap tileMap;
Camera camera;
Hero hero;

//--------------------------------------------------------------
void ofApp::setup(){
	tileMap.init();
	hero.init();
}

//--------------------------------------------------------------
void ofApp::update(){
	float secs = ofGetLastFrameTime();
	hero.update(secs, tileMap.getMapHeight());
	camera.update(hero.getPosition(), ofVec2f(tileMap.getMapWidth(), tileMap.getMapHeight()));

	ofVec2f direction = mousePos - hero.getPosition();
	float distance = direction.length();
	if (distance < 2) {
		hero.setDirection(ofVec2f(0, 0));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	tileMap.draw(camera.getPosition());
	hero.draw(camera.getPosition());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	hero.setDirection(mousePos);
	hero.getDirection().normalize();
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
