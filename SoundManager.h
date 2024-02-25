#pragma once
#include <string>
#include <map>
#include <SDL_mixer.h>

class SoundManager //singleton class (one instance at a time)
{
public:
	
	//to ensure that only one instance of the class can be created, and that the instance is always accessible from any part of the program.
	static SoundManager* Instance() //static => the constructor can be private
	{
		if (s_mInstance == 0)
		{
			s_mInstance = new SoundManager();

		}
		return s_mInstance;
	}
	
	bool load(const char* fileName, std::string id, int type);
	void playSound(std::string id, int loop, int ms = 0); 
	void playMusic(std::string id, int loop, int ms = 0);

private:
	static SoundManager* s_mInstance;//one instance everywhere
	std::map<std::string, Mix_Chunk*> s_mSfxs; //variable that contains a sound file
	std::map<std::string, Mix_Music*> s_mMusic; //variable that contains a music file
	SoundManager(); //private constructor because of static SoundManager* Instance()
	~SoundManager();
};
