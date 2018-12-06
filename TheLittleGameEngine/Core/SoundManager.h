#ifndef __TLGE_SOUND_MANAGER_H__
#define __TLGE_SOUND_MANAGER_H__

#include <string>

#undef PlaySound

namespace TLGE
{
	enum SoundGroups
	{
		SoundGroup_Music = 0,
		SoundGroup_Effects = 1,
	};

	class SoundManager
	{
	public:
		SoundManager() {}
		virtual ~SoundManager() {}

		virtual void PlaySound(std::string filepath) = 0;
		virtual void PlayMusic(std::string filepath) = 0;
		virtual void PauseMusic() = 0;
		virtual void HaltMusic() = 0;
		virtual void ResumeMusic() = 0;
		virtual void SetMusicVolume(int aVolume) = 0;
		virtual void SetSFXVolume(int aVolume) = 0;
	private:
	};
}

#endif