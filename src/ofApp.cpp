#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int numCountries = 4;
    for(int i = 0; i < numCountries; i++){
        country newCountry;
        countries.push_back(newCountry);
    }
    centre.x = 0;
    centre.y = 0;
    countrySize = 125;
    noise.load("p1.mp3");
    noise.setLoop(true);
    noise.play();
    noise.setVolume(0.5f);
    
    ofSoundPlayer p1,p2,p3,p4;
    p1.load("c.mp3");
    p2.load("d.mp3");
    p3.load("f.mp3");
    p4.load("g.mp3");
    soundVector.push_back(p1);
    soundVector.push_back(p2);
    soundVector.push_back(p3);
    soundVector.push_back(p4);
    
    for(int k = 0; k < soundVector.size(); k++){
        soundVector[k].setMultiPlay(true);
        soundVector[k].setLoop(true);
        soundVector[k].setVolume(0.6);
        play.push_back(false);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(noise.getPosition() > 0.7){
        noise.setPosition(0);
    }
    for(int k = 0; k < soundVector.size(); k++){
        if(play[k]){
            if(!soundVector[k].isPlaying()){
                soundVector[k].play();
            }
        }else{
            soundVector[k].stop();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(100, 100, 200);
    ofDrawCircle(centre, countrySize);
    for(int i = 0; i < countries.size(); i++){
        countries[i].draw(i);
        dist = ofDist(centre.x, centre.y, countries[i].point.x, countries[i].point.y);
        if(dist - countrySize < countries[i].radius){
            ofDrawCircle(countries[i].point.x, countries[i].point.y, 30);
            play[i] = true;
           
        }else{
            play[i] = false;
        }
    }
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
country::country(){
    radius = 10;
    r = ofRandom(30,220);
    g = ofRandom(30,220);
    b = ofRandom(30,220);
}

country::~country(){
    
}

void country::draw(float index){
    time = ofGetElapsedTimef();
    float speed = 0.01;
    float posX = (index*1.1) + 39.87;
    float posY = (index*1.1) + 42.69;
    
    point.x = (ofGetWidth()*2.0) * ofNoise(time * (speed*(index+1)) + posX) - ofGetWidth();
    point.y = (ofGetHeight()*2.0) * ofNoise(time * (speed*(index+1)) + posY) - ofGetHeight();
    ofSetColor(r, g, b, 110);
    ofDrawCircle(point, radius);
    
}
