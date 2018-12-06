#include "EnginePCH.h"

namespace TLGE
{

	//need to move eventually
	SoundManagerWin32::SoundManagerWin32()
	{
		SFXvolume = 100;
		// Set some default values
		int audio_rate = 44100;
		Uint16 audio_format = MIX_DEFAULT_FORMAT;
		int audio_channels = 2;
		int audio_buffers = 512;
		// Initialize SDL audio only
		SDL_Init(SDL_INIT_AUDIO);
		// Initialize SDL Mixer
		if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers))
		{
			assert(false);
		}

		// Get the number of audio channels available
		int numchannels = Mix_GroupCount(-1);
		// Dedicate channel 0 for music and the rest for sound effects
		Mix_GroupChannel(0, SoundGroup_Music);
		Mix_GroupChannels(1, numchannels - 1, SoundGroup_Effects);
	}

	SoundManagerWin32::~SoundManagerWin32()
	{
		//nothing to do
	}

	void SoundManagerWin32::PlaySound(std::string aFilepath)
	{
		// Load the sound
		Mix_Chunk* pSound = Mix_LoadWAV(aFilepath.c_str());
		// Find a free channel, use the last one used if they’re all taken
		int channel = Mix_GroupAvailable(SoundGroup_Effects);
		if (channel == -1)
			channel = Mix_GroupOldest(SoundGroup_Effects);
		// Play the sound
		Mix_VolumeChunk(pSound, SFXvolume);
		int channelused = Mix_PlayChannel(channel, pSound, 0);
	}

	void SoundManagerWin32::PlayMusic(std::string aFilepath)
	{
		// Load the sound
		//Mix_Chunk* pSound 
		pMusic = Mix_LoadWAV(aFilepath.c_str());
		// Find a free channel, use the last one used if they’re all taken
		int channel = Mix_GroupAvailable(SoundGroup_Music);
		if (channel == -1)
			channel = Mix_GroupOldest(SoundGroup_Music);

		// Play the sound, -1 for infinite looping, 0 for once, ect...
		int channelused = Mix_PlayChannel(channel, pMusic, -1);



	}

	void SoundManagerWin32::PauseMusic()
	{

		Mix_Pause(0);

	}

	void SoundManagerWin32::HaltMusic()
	{

		Mix_HaltChannel(0);

	}

	void SoundManagerWin32::ResumeMusic()
	{

		Mix_Resume(0);

	}

	void SoundManagerWin32::SetMusicVolume(int aVolume)
	{
		//goes from 0 to 128
		Mix_VolumeChunk(pMusic, aVolume);
	}

	void SoundManagerWin32::SetSFXVolume(int aVolume)
	{
		//goes from 0 to 128
		SFXvolume = aVolume;
	}

}