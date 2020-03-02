#include "audioManager.h"

audioManager::audioManager()
{
	loadCountrySoundBank();
}




void audioManager::setWalker()
{

}

void audioManager::loadCountrySoundBank()
{

	string path = "/countrySoundFiles/" + countryName;

	ofDirectory dir(path);
	dir.listDir();
	cout << "Directory size: " + dir.size() << endl;


}

void audioManager::playLeadLoop(bool b_shouldBePlaying)
{
	if (b_shouldBePlaying)
	{
		int index = ofRandom(0, soundBankLead.size());
		soundBankLead[index].play();

	}
}

void audioManager::playPercussionLoop(bool b_shouldBePlaying)
{
	if (b_shouldBePlaying)
	{
		int index = ofRandom(0, soundBankPerc.size());
		soundBankPerc[index].play();

	}
}


