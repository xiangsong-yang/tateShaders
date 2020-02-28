#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(24);
}

//--------------------------------------------------------------
void ofApp::update() {
        if (ofGetFrameNum()%100 == 0) {
            shader.unload();
            ofLog() << i;
            setShader();
            
            if (!shader.isLoaded()) {
                i = 0;
                setShader();
            }
            i++;
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(120);
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
      shader.setUniform2f("mouse", mouseX, mouseY);
      shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

//--------------------------------------------------------------
void ofApp::setShader () {
    string path = std::to_string(i) + "/shader";
    shader.load(path);
}
