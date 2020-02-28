#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
        void exit();
        void newMidiMessage(ofxMidiMessage & message);
        
        void setShader();
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        ofImage myImage;//图像的变量名存在这里
        ofPixels pxdata;//orginal pixel
        ofPixels pxempty;//store the pixel
        ofTexture texture;//for draw maybe
    
    // shader loop moritz
    ofEasyCam cam;
    ofShader shader;
    ofSpherePrimitive sphere;
    
    int i = 0; // iterator for for loop
    int dirCount = 3; // number of directories containing shaders
    
    // midi yilin
    ofxMidiIn midi;
    vector <ofxMidiMessage> messages;
    
    int velocity;
    std::vector< int > pitches;
    
    int x;
    int y;
    int rad;
    
    std::vector<int> positionXs;
    std::vector<int> positionYs;
    std::vector<int> radiuses;
    std::vector<int> alphas;
    int imgw;
    int imgh;
    std::vector <int> timers;
    
    int samplelength;
    int scl = 5; //remain to use maybe no use
    std::vector<int> sample;//sampling dots dynamic array
    int timecontrol = 0;
    int lastupdate = 0;
};
