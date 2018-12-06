#ifndef __SOUND_MANAGER_ANDROID_H__
#define __SOUND_MANAGER_ANDROID_H__

#include "../Core/SoundManager.h"

namespace TLGE
{
	class SoundManagerAndroid : public SoundManager
	{
	public:
		SoundManagerAndroid();
		virtual ~SoundManagerAndroid();

		void PlaySound(std::string filepath);
		void PlayMusic(std::string filepath);
		void PauseMusic();
		void HaltMusic();
		void ResumeMusic();
		void SetMusicVolume(int aVolume);
		void SetSFXVolume(int aVolume);

	protected:
		static const int MAX_SOUNDS = 255;
		static const int MAX_QUEUED_SOUNDS = 10;

		// OpenSL Objects
		SLObjectItf g_ppOpenSLEngine;
		SLObjectItf g_ppOutputMix;
		SLObjectItf g_ppAudioPlayer;

		int m_QueuedSounds[MAX_QUEUED_SOUNDS];
		int m_NumQueuedSounds;
	};
}

#endif