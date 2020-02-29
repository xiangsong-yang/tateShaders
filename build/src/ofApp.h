#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxMidi.h"
#define HOST "localhost"
#define PORT 12456
class ofApp : public ofBaseApp, public ofxMidiListener {

    public:
        void setup();
        void update();
        void draw();
        void exit();
        void newMidiMessage(ofxMidiMessage & message);
     void setShader();

        void pressLong();
        void pressHigh();
        void pressFast();
        void pressNormal();
        void defaultScene();
        void nextshader();


        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
       
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    //----shader
    ofEasyCam cam;
    ofShader shader;
    ofSpherePrimitive sphere;
    
    int shaderNumber = 0; // iterator for for loop
    int dirCount = 1; // number of directories containing shaders


///----iimage
        ofImage myImage;//ÕºœÒµƒ±‰¡ø√˚¥Ê‘⁄’‚¿Ô
        ofPixels pxdata;//orginal pixel
        ofPixels pxempty;//store the pixel
        ofTexture texture;//for draw maybe

        ofxMidiIn midi;
        MidiStatus status;
        vector <ofxMidiMessage> messages;
        vector <ofxMidiMessage> notes;
        ofxMidiTimecode defaultTime;
        int sum_of_vel;
        float timer;
        int numPressed = 0;

        ofxOscSender sender;

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
