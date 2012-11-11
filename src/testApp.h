#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Rect.h"

#define PORT 7771
#define NUM 31
#define DIV 16

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxOscReceiver receiver;
    ofTrueTypeFont font;
    
    int visual_Selection;
    int freq;
    //float duration[NUM];
    float duration;
    
    int speed;

    int rectNum;
    //rect myRect[NUM];
    vector<rect *> myRect;


		
};



