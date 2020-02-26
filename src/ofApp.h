#pragma once

#include "ofMain.h"

class country {
    
public:
    
    
    void draw(float index);
    float time;
    int radius,r,g,b;
    ofVec3f point;
    country();
    ~country();
    
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
    vector<country> countries;
    ofVec3f centre;
    float dist;
    int countrySize;
    ofSoundPlayer noise;
    vector<ofSoundPlayer> soundVector;
    vector<bool> play;
};
