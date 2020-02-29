#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(24);
    
    //----
    
    sender.setup(HOST, PORT);

    midi.listInPorts();
    midi.openPort(1);
    //    midi.openPort("Impact LX61+ (MIDI1)");
    midi.addListener(this);
    setShader();
    
}

//--------------------------------------------------------------
void ofApp::update() {
    
    if (numPressed == 0) {
        //        std::cout<< "released\n";
        if (ofGetElapsedTimef() - timer > 3.1 && ofGetElapsedTimef() - timer < 3.12) {
            //        std::cout<<"sum_of_vel" << sum_of_vel<< "   \n";
            sum_of_vel = 0;
            defaultScene();
        }
    }
    
}
void ofApp::nextshader(){
   
                shader.unload();
                ofLog() << shaderNumber;
                setShader();
                
                if (!shader.isLoaded()) {
                    shaderNumber = 0;
                    setShader();
                }
                shaderNumber++;
            }
     
    

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(240);
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
      shader.setUniform2f("mouse", mouseX, mouseY);
      shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    
    
    ///----
    for (int i = 0; i < messages.size(); i++) {
        ofxMidiMessage & message = messages[i];

    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'd' || key == 'D') {
        defaultScene();
    }
    if (key == 'l' || key == 'L') {
        pressLong();
    }
    if (key == 'h' || key == 'H') {
        pressHigh();
    }
    if (key == 'F' || key == 'f') {
        pressFast();
    }
    
}

void ofApp::exit() {
    midi.closePort();
    midi.removeListener(this);
}
//--------------------------------------------------------------

void ofApp::newMidiMessage(ofxMidiMessage & message) {
    messages.push_back(message);
    if (messages.size() > 64) {
        messages.erase(messages.begin());
    }

    if (message.velocity > 50) {
        sum_of_vel += 1;
    }
    sum_of_vel += message.velocity;


    if (sum_of_vel > 500) {
        //time time time ofGetElapsedTimef()
        pressFast();
    }

    if (message.pitch >= 84) {
        pressHigh();
    }


    if (message.status == MidiStatus::MIDI_NOTE_ON) {
        numPressed += 1;
        timer = ofGetElapsedTimef();
    }
    if (message.status == MidiStatus::MIDI_NOTE_OFF) {
        numPressed -= 1;
        timer = ofGetElapsedTimef();
    std:cout << "timer = ofGetElapsedTimef()\n";

    }
    if (numPressed >= 5) {
        pressLong();
    }
    

}
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
    string path = std::to_string(shaderNumber) + "/shader";
    shader.load(path);
}
void ofApp::defaultScene() {
    ofxOscMessage m;
    m.setAddress("/stop");
    m.addIntArg(87);
    sender.sendMessage(m);
    m.setAddress("/campfire");
    //    m.addStringArg( "campfire" );
    m.addIntArg(78);
    std::cout << "default\n";
    sender.sendMessage(m);
}

void ofApp::pressHigh() {
    ofxOscMessage m;
    m.setAddress("/highNotes");
    //    m.addStringArg( "high" );
    m.addIntArg(6);
    std::cout << "high\n";
    sender.sendMessage(m);
}
void ofApp::pressLong() {
    ofxOscMessage m;
    m.setAddress("/stop");
    m.addIntArg(87);
    sender.sendMessage(m);

    m.setAddress("/longNotes");
    //    m.addStringArg( "long" );
    m.addIntArg(4);
    std::cout << "long\n";
    sender.sendMessage(m);




}
void ofApp::pressFast() {
    ofxOscMessage m;
    m.setAddress("/stop");
    m.addIntArg(87);
    sender.sendMessage(m);

    m.setAddress("/fastMode");
    m.addIntArg(3);
    std::cout << "fastMode\n";
    sender.sendMessage(m);

    //    sum_of_vel = 0;
}

void ofApp::pressNormal() {
    ofxOscMessage m;
    m.setAddress("/normalPress");
    m.addIntArg(3);
    std::cout << "normalPress\n";
    sender.sendMessage(m);
}
