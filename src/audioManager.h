#pragma once

/*
CLASS OUTLINE:
Point to a collection of samples/loops that are related to the coutry
Provide information about the audio being played (spectro, metadata, realtime or preload)
Provide

*/

#include "ofMain.h"

class audioManager : public walker
{
public:
	
	audioManager();

	void setWalker();

	void loadCountrySoundBank();

	void playLeadLoop(bool b_shouldBePlaying);
	void playPercussionLoop(bool b_shouldBePlaying);

	string countryName;

	vector<ofSoundPlayer> soundBankLead;
	vector<ofSoundPlayer> soundBankPerc;


	

};

