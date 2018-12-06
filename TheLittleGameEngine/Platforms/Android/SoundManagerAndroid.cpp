#include "EnginePCH.h"

SLEngineItf g_ppEngineInterface;
SLVolumeItf g_ppOutputMixVolume;

namespace TLGE
{
	SoundManagerAndroid::SoundManagerAndroid()
	{
		m_NumQueuedSounds = 0;

		g_ppOpenSLEngine = 0;
		g_ppOutputMix = 0;
		g_ppAudioPlayer = 0;

		// Create the OpenSL Engine
		{
			SLEngineOption EngineOptions[] =
			{
				(SLuint32)SL_ENGINEOPTION_THREADSAFE,
				(SLuint32)SL_BOOLEAN_TRUE
			};
			slCreateEngine(&g_ppOpenSLEngine, 1, EngineOptions, 0, 0, 0);

			// Allocate the OpenSL Engine. False for synchronous allocation.
			(*g_ppOpenSLEngine)->Realize(g_ppOpenSLEngine, SL_BOOLEAN_FALSE);

			// Get the engine interface
			(*g_ppOpenSLEngine)->GetInterface(g_ppOpenSLEngine, SL_IID_ENGINE, (void*)&g_ppEngineInterface);
		}

		// Create an Output Mix object
		{
			(*g_ppEngineInterface)->CreateOutputMix(g_ppEngineInterface, &g_ppOutputMix, 0, 0, 0); //1, ids, req );

																											// Allocate the Output Mix object. False for synchronous allocation.
			(*g_ppOutputMix)->Realize(g_ppOutputMix, SL_BOOLEAN_FALSE);

		}
	}

	SoundManagerAndroid::~SoundManagerAndroid()
	{
		(*g_ppAudioPlayer)->Destroy(g_ppAudioPlayer);
		(*g_ppOutputMix)->Destroy(g_ppOutputMix);
		(*g_ppOpenSLEngine)->Destroy(g_ppOpenSLEngine);
	}

	void SoundManagerAndroid::PlaySound(std::string aFilepath)
	{
		long size = 0;
		char* fileText;

		AAssetManager* pAssetManager = g_pAndroidApp->activity->assetManager;

		AAsset* asset = AAssetManager_open(pAssetManager, (aFilepath + ".a").c_str(), AASSET_MODE_STREAMING);
		if (asset == 0)
			return;

		if (asset)
		{
			size = AAsset_seek(asset, 0, SEEK_END);
			AAsset_seek(asset, 0, SEEK_SET);

			fileText = new char[size + 1];
			AAsset_read(asset, fileText, size);
			fileText[size] = 0;

			AAsset_close(asset);
		}


		MyWaveDescriptor wav = WaveLoader::ParseWaveBuffer(fileText, size);
		SLint16* actualSound = new SLint16[wav.datasize / wav.bytespersample];
		for (int i = 0; i < wav.datasize / wav.bytespersample; i++)
		{
			actualSound[i] = wav.data[i];
		}

		// Setup the data source structure for the buffer queue
		//   works as well with SLDataLocator_AndroidSimpleBufferQueue, SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE and SL_IID_ANDROIDSIMPLEBUFFERQUEUE
		SLDataLocator_BufferQueue bufferQueue;
		bufferQueue.locatorType = SL_DATALOCATOR_BUFFERQUEUE;
		bufferQueue.numBuffers = 1;

		// Setup the format of the content in the buffer queue
		SLDataFormat_PCM pcmDataFormat;
		pcmDataFormat.formatType = SL_DATAFORMAT_PCM;
		pcmDataFormat.numChannels = 1;
		pcmDataFormat.samplesPerSec = SL_SAMPLINGRATE_44_1;
		pcmDataFormat.bitsPerSample = SL_PCMSAMPLEFORMAT_FIXED_16;
		pcmDataFormat.containerSize = 16;
		pcmDataFormat.channelMask = SL_SPEAKER_FRONT_CENTER;
		pcmDataFormat.endianness = SL_BYTEORDER_LITTLEENDIAN;

		SLDataSource audioSource;
		audioSource.pLocator = &bufferQueue;
		audioSource.pFormat = &pcmDataFormat;

		// Setup the data sink structure
		SLDataLocator_OutputMix locatorOutputMix;
		locatorOutputMix.locatorType = SL_DATALOCATOR_OUTPUTMIX;
		locatorOutputMix.outputMix = g_ppOutputMix;

		SLDataSink audioSink;
		audioSink.pLocator = &locatorOutputMix;
		audioSink.pFormat = 0;

		// Create an audio player
		{
			// Set ids required for audioPlayer interface
			const SLInterfaceID ids[] = { SL_IID_BUFFERQUEUE };
			const SLboolean req[] = { SL_BOOLEAN_TRUE };

			(*g_ppEngineInterface)->CreateAudioPlayer(g_ppEngineInterface, &g_ppAudioPlayer, &audioSource, &audioSink, 1, ids, req);

			// Realize the player in synchronous mode.
			(*g_ppAudioPlayer)->Realize(g_ppAudioPlayer, SL_BOOLEAN_FALSE);
		}

		// Get interfaces
		SLPlayItf playInterface;
		(*g_ppAudioPlayer)->GetInterface(g_ppAudioPlayer, SL_IID_PLAY, &playInterface);

		SLBufferQueueItf bufferQueueInterface;
		(*g_ppAudioPlayer)->GetInterface(g_ppAudioPlayer, SL_IID_BUFFERQUEUE, &bufferQueueInterface);

		// Enqueue our entire buffer
		(*bufferQueueInterface)->Clear(bufferQueueInterface);

		(*bufferQueueInterface)->Enqueue(bufferQueueInterface, (SLint16*)wav.data, wav.datasize);

		// Start playback
		(*playInterface)->SetPlayState(playInterface, SL_PLAYSTATE_PLAYING);
	}

	void SoundManagerAndroid::PlayMusic(std::string aFilepath)
	{
	}

	void SoundManagerAndroid::PauseMusic()
	{
	}

	void SoundManagerAndroid::HaltMusic()
	{
	}

	void SoundManagerAndroid::ResumeMusic()
	{
	}

	void SoundManagerAndroid::SetMusicVolume(int aVolume)
	{
	}

	void SoundManagerAndroid::SetSFXVolume(int aVolume)
	{
	}

}