#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    
    receiver.setup(PORT);
    
    font.loadFont("Arial Unicode.ttf", 9);
    ofBackground(0, 0, 0);
    rectNum = 0;
    visual_Selection = 0;
    speed = 30;
    
    vector<rect *>::iterator rectIt;
    rectIt = myRect.begin();
}

//--------------------------------------------------------------
void testApp::update(){
    vector<rect *>::iterator rectIt;
    rectIt = myRect.begin();
    
    while (receiver.hasWaitingMessages()) {

        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if(m.getAddress() == "/event"){
            
            freq = m.getArgAsInt32(0);
            duration = m.getArgAsFloat(1);
            
            if (visual_Selection == 0){
             ofPoint pos;
                for (int i = myRect.size(); i >= 0; --i) {
                    
                    if (myRect.size() == 0) {
                        pos = ofPoint(0, ofGetHeight()/2);
                    }else{
                        if (i != myRect.size()) {
                            pos = myRect[i]->getPos();
                            myRect[i]->setPos(ofPoint(pos.x + ofGetWidth()/DIV, pos.y));
                            myRect[i]->setWidth(myRect[i]->getWidth());
                        }
                    }
                }
                pos.x = 0; //add step point to the last position
                pos.y = ofGetHeight()/2; // set y
                
                myRect.insert(rectIt, new rect(ofPoint(pos.x, ofGetHeight()/2), duration * ofGetWidth()/DIV, 10));
                
            }
            
            if (visual_Selection == 1) {
                
                myRect.push_back(new rect(ofPoint(0, ofGetWidth()/2), duration * 500, 10));
                //myRect.insert(rectIt, new rect(ofPoint(0, ofGetWidth()/2), duration * 500, 10));
                //cout << myRect[rectNum]->getPos().x <<endl;

            }
            
            rectNum += 1;
            if (rectNum >= NUM) {
                rectNum = 0;
            }
        }
        
    }
    
    if (visual_Selection == 1) {
        for(int i = 0; i < myRect.size(); i++){
            ofPoint pos;
            pos.x = myRect[i]->getPos().x + speed;
            pos.y = ofGetHeight()/2;
            myRect[i]->setPos(ofPoint(pos.x, pos.y));
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    string buf_1;
    string buf_2;
	buf_1 = "freq : " + ofToString(myRect.size());
    buf_2 = "duration : " + ofToString(duration);
    
    font.drawString(buf_1, 10,20);
    font.drawString(buf_2, 10,40);
    
    for (int i = 0; i < myRect.size(); i++) {
        myRect[i]->draw();
    }
    //*/
    //ofSetBackgroundAuto(false);
    //myRect[1].draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == '0') {
        visual_Selection = 0;
    }
    if (key == '1') {
        visual_Selection = 1;
    }
    
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

