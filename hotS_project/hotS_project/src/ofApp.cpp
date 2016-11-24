#include "ofApp.h"
#include "Menu.h"
#include "Game.h"

//--------------------------------------------------------------
void ofApp::setup(){
	manager.init(new Game());
}

//--------------------------------------------------------------
void ofApp::update(){
	manager.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	manager.draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	KEYS.onPress(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	KEYS.onRelease(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	MOUSE.onPress(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	MOUSE.onRelease(x, y, button);
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
