#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(24);
    
    // ------------- midi yilin -------------
    myImage.load("test2.jpeg");
    
    
    
    midi.openPort(0);
    //    "Impact LX61+ (MIDI1)"
    midi.addListener(this);
    //    myImage.load("test2.jpg");
    myImage.setImageType(OF_IMAGE_COLOR_ALPHA);
    //    ofLoadImage(pxdata, "test2.jpg");//load the pixel value into pxdata
    //    ofLoadImage(pxempty, "test2.jpg");
    //
    
    
    //       imgw = myImage.getWidth();//width
    //       imgh = myImage.getHeight();//height
    ofBackground(20, 20, 20);
}

void ofApp::update() {
    // ------------- Shader loop moritz -------------
    // shader.load("3/shader");
    
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
    
    
    // ------------- midi yilin -------------
    if( positionXs.size() == 0){
        for (int i = 0; i <20; i++){
            positionXs.push_back(ofRandom(100,ofGetWidth()-100));
            positionYs.push_back(ofRandom(100, ofGetHeight()-100));
            // positionXs.push_back(ofRandom(100,imgw-100));
            // positionYs.push_back(ofRandom(100,imgh-100));
            radiuses.push_back(ofRandom(5,70));
            alphas.push_back(ofRandom(100, 200));
            timers.push_back(ofGetElapsedTimeMillis());
        }
        
    }
}

void ofApp::draw(){
    // ------------- shader loop moritz -------------
    ofSetColor(120);
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("mouse", mouseX, mouseY);
    shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    
    // ------------- midi yilin -------------
    //    myImage.draw(0, 0);
    
    for (int i = 0; i < positionYs.size(); i++){
        ofColor color = myImage.getColor(positionXs[i], positionYs[i]);
        int alpha = 200 -  (ofGetElapsedTimeMillis()-timers[i]) / 35;
        if (alpha <0){
            positionXs.erase(positionXs.begin());
            positionYs.erase(positionYs.begin());
            radiuses.erase(radiuses.begin());
            timers.erase(timers.begin());
            timecontrol = ofGetElapsedTimeMillis();
            std::cout << "size   "<<positionXs.size() << "\n";
        }
        //            int a;
        //            if (alpha < 0){
        //                a = (-alpha%200);
        //            }
        //            if(alpha >= 0){
        //                a = alpha;
        //            }
        ofSetColor(color, alpha);
        ofDrawCircle(positionXs[i], positionYs[i], radiuses[i]);//velocity?
        std:: cout <<timers[i] <<"   "<< ofGetElapsedTimeMillis()<<"alpha  "<< alpha <<" \n";
    }
    
    if(ofGetElapsedTimeMillis() - timecontrol>1500 && positionXs.size() > 0){
        positionYs.erase(positionYs.begin());
        positionXs.erase(positionXs.begin());
        radiuses.erase(radiuses.begin());
        timers.erase(timers.begin());
        timecontrol = ofGetElapsedTimeMillis();
        std::cout << "size   " << positionXs.size() << "\n";
    }
}

void ofApp::exit(){
    midi.closePort();
    midi.removeListener(this);
}

void ofApp::newMidiMessage(ofxMidiMessage & message) {
    x = floor((message.pitch-34) * ofGetWidth()/72 + ofRandom(ofGetWidth()/10));
    y = floor((message.pitch-34) * ofGetHeight()/290 + ofRandom(ofGetHeight()/1.1));
    positionXs.push_back(x);
    positionYs.push_back(y);
    timecontrol = ofGetElapsedTimeMillis();
    timers.push_back(ofGetElapsedTimeMillis());
    radiuses.push_back(floor(message.velocity)/1.6+15);
    
    if (messages.size() > 128){
        positionYs.erase(positionYs.begin());
        positionXs.erase(positionXs.begin());
        radiuses.erase(radiuses.begin());
        timers.erase(timers.begin());
    }
    std::cout << "pitch:   " << message.pitch << "   velocity:   " << message.velocity << "   \n";
}

void ofApp::keyPressed(int key){
    
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::windowResized(int w, int h){
    myImage.resize(w, h);
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

void ofApp::setShader () {
    string path = std::to_string(i) + "/shader";
    shader.load(path);
}
