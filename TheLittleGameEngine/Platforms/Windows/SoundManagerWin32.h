#ifndef __SOUND_MANAGER_WIN32_H__
#define __SOUND_MANAGER_WIN32_H__

#include "../Core/SoundManager.h"

namespace TLGE
{
	class SoundManagerWin32 : public SoundManager
	{

	private:

		Mix_Chunk* pMusic;
		int SFXvolume;

	public:
		SoundManagerWin32();
		virtual ~SoundManagerWin32();

		void PlaySound(std::string filepath);
		void PlayMusic(std::string filepath);
		void PauseMusic();
		void HaltMusic();
		void ResumeMusic();
		void SetMusicVolume(int aVolume);
		void SetSFXVolume(int aVolume);
	};
}

#endif