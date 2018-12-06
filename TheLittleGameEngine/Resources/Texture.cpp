#include "EnginePCH.h"

namespace TLGE
{
	Texture::Texture():
		Resource(),
		//TODO: fix 0 to nullptr
		m_textureLocation(0)
	{
		//nothing to do
	}
	Texture::~Texture()
	{
		//TODO: fix 0 to nullptr
		if (m_textureLocation != 0)
		{
			delete[] m_textureLocation;
		}
	}

	void Texture::Load()
	{
		unsigned char* image;
		unsigned int width, height;
		unsigned char* fileText;
		int size;
#if defined(__WINDOWS_BUILD__)
		FILE* textureFile;
		fopen_s(&textureFile, m_textureLocation, "rb");

		assert(textureFile != NULL);

		fseek(textureFile, 0, SEEK_END);
		size = ftell(textureFile);
		fseek(textureFile, 0, SEEK_SET);

		fileText = new unsigned char[size + 1];
		fread(fileText, 1, size, textureFile);
		fileText[size] = 0;

		fclose(textureFile);
#elif defined(__ANDROID_BUILD__)
		AAssetManager* pAssetManager = g_pAndroidApp->activity->assetManager;

		AAsset* asset = AAssetManager_open(pAssetManager, m_textureLocation, AASSET_MODE_STREAMING);
		if (asset == 0)
			return;

		if (asset)
		{
			size = AAsset_seek(asset, 0, SEEK_END);
			AAsset_seek(asset, 0, SEEK_SET);

			fileText = new unsigned char[size + 1];
			AAsset_read(asset, fileText, size);
			fileText[size] = 0;

			AAsset_close(asset);
		}
#endif

		unsigned int error = lodepng_decode32(&image, &width, &height, fileText, size);

		///////////
		unsigned int* temp;
		temp = new unsigned int[width];
		int linesize = width * sizeof(unsigned int);

		unsigned int* buffer32 = (unsigned int*)image;
		for (unsigned int y = 0; y<height / 2; y++)
		{
			int LineOffsetY = y*width;
			int LineOffsetHminusY = (height - 1 - y)*width;

			memcpy(temp, &buffer32[LineOffsetY], linesize);
			memcpy(&buffer32[LineOffsetY], &buffer32[LineOffsetHminusY], linesize);
			memcpy(&buffer32[LineOffsetHminusY], temp, linesize);
		}

		delete[] temp;
		delete[] fileText;
		///////////

		assert(!error);

		m_textureHandle = 0;
		glGenTextures(1, &m_textureHandle);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_textureHandle);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glBindTexture(GL_TEXTURE_2D, 0);

		delete[] image;
	}
	void Texture::CreateTexture(char* aTextureFileLocation)
	{
		m_identifier = new char[255];

#ifdef  WIN32
		strcpy_s(m_identifier, 255, "TEXTURE");
		strcat_s(m_identifier, 255, aTextureFileLocation);
#else
		strcpy(m_identifier, "TEXTURE");
		strcat(m_identifier, aTextureFileLocation);
#endif

		if (Resource::GetResource(m_identifier) != nullptr)
		{
			m_original = (Texture*)Resource::GetResource(m_identifier);
			return;
		}

		Resource::AddResource(m_identifier, this);
		m_original = this;

		m_textureLocation = new char[strlen(aTextureFileLocation)];

		//TODO:Write function for this
#ifdef  WIN32
		strcpy_s(m_textureLocation, strlen(aTextureFileLocation) + 1, aTextureFileLocation);
#else
		strcpy(m_textureLocation, aTextureFileLocation);
#endif //  WIN32
	}
}