#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(24);
}

//--------------------------------------------------------------
void ofApp::update() {
        if (ofGetFrameNum()%duration == 0) {
            i++;
            
            string urlVert = "shadersGL3/" + std::to_string(i) + "/shader.vert";
            string urlFrag = "shadersGL3/" + std::to_string(i) + "/shader.frag";
            shader.load(urlVert, urlFrag);
            
            //ofLog() << i;
            
            if (i >= dirCount)  {
                i = 0;
            }
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
