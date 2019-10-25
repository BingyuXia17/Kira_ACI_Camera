#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    cam.setup(640, 480);
    
    tracker.setup();
    tracker.setRescale(.5);
    classifier.load("expressions");
    
    for(int i=0; i<BALLS; i++){
        groupOfBalls[i].setup(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), (i+1) * 10);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        if(tracker.update(toCv(cam))) {
            classifier.classify(tracker);}
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    ofSetColor(255);
//    cam.draw(0, 0);
//    tracker.draw();
    
    int w = 200, h = 40;
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(5, 10);
    int n = classifier.size();
    int primary = classifier.getPrimaryExpression();
    for(int i = 0; i < n; i++){
        ofSetColor(i == primary ? ofColor::red : ofColor::orange);
        ofDrawRectangle(0, 0, w * 2 * classifier.getProbability(i) + .5, ofGetHeight()/2);
//        ofSetColor(255);
//        ofDrawBitmapString(classifier.getDescription(i), 5, 9);
        ofTranslate(0, h + 5);
    }
//   Face expression recognition reference: https://github.com/kylemcdonald/ofxFaceTracker/tree/master/example-expression
    for(int i = 0; i < 10; i++){
    ofSetColor(255,255,255);
        ofDrawRectangle(0,w, w * 3 * classifier.getProbability(i),480);}
    
    for(int i = 0; i < 10; i++){
        if (classifier.getProbability(i)>0.8) {
            for(int i=0; i<BALLS; i++){
            ofSetColor(0,0,0);
                groupOfBalls[i].draw(200, ofRandom(0, 640),50 * classifier.getProbability(i));}
        }
    }
    ofPopMatrix();
    ofPopStyle();
    
//    for(int i=0; i<BALLS; i++){
//        groupOfBalls[i].draw();}
//
//    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), ofGetWidth() - 20, ofGetHeight() - 10);
//    ofDrawBitmapStringHighlight(
//        string() +
//        "r - reset\n" +
//        "e - add expression\n" +
//        "a - add sample\n" +
//        "s - save expressions\n"
//        "l - load expressions",
//        14, ofGetHeight() - 7 * 12);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if(key == 'r') {
//        tracker.reset();
//        classifier.reset();
//    }
//    if(key == 'e') {
//        classifier.addExpression();
//    }
//    if(key == 'a') {
//        classifier.addSample(tracker);
//    }
//    if(key == 's') {
//        classifier.save("expressions");
//    }
//    if(key == 'l') {
//        classifier.load("expressions");
//    }
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
