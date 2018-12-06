#include "EnginePCH.h"

namespace TLGE
{
	ShaderProgram::ShaderProgram() :
		Resource(),
		//TODO: fix 0 to nullptr
		m_vertFileLocation(0),
		//TODO: fix 0 to nullptr
		m_fragFileLocation(0),
		m_original(nullptr)
	{
		//nothing to do
	}
	ShaderProgram::~ShaderProgram()
	{
		//TODO: fix 0 to nullptr
		if (m_vertFileLocation != 0)
		{
			delete[] m_vertFileLocation;
		}
		//TODO: fix 0 to nullptr
		if (m_fragFileLocation != 0)
		{
			delete[] m_fragFileLocation;
		}
	}

	void ShaderProgram::Load()
	{
		m_program = glCreateProgram();

		GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
		{
			char* fileText;
			//TODO: make function for this(less repeat code)
#if defined(__WINDOWS_BUILD__)
			FILE* shaderFile;
			fopen_s(&shaderFile, m_vertFileLocation, "rb");

			assert(shaderFile != NULL);

			fseek(shaderFile, 0, SEEK_END);
			int fileLength = ftell(shaderFile);
			fseek(shaderFile, 0, SEEK_SET);

			fileText = new char[fileLength + 1];
			fread(fileText, 1, fileLength, shaderFile);
			fileText[fileLength] = 0;

			fclose(shaderFile);
#elif defined(__ANDROID_BUILD__)
			AAssetManager* pAssetManager = g_pAndroidApp->activity->assetManager;

			AAsset* asset = AAssetManager_open(pAssetManager, m_vertFileLocation, AASSET_MODE_STREAMING);
			if (asset == 0)
				return;

			if (asset)
			{
				int size = AAsset_seek(asset, 0, SEEK_END);
				AAsset_seek(asset, 0, SEEK_SET);

				fileText = new char[size + 1];
				AAsset_read(asset, fileText, size);
				fileText[size] = 0;

				AAsset_close(asset);
			}
#endif
			const char* strings[] = { "precision highp float;", fileText };
			glShaderSource(vertShader, 2, strings, NULL);
			glCompileShader(vertShader);
#if defined(__ANDROID_BUILD__)
			int compiled = 0;
			glGetShaderiv(vertShader, GL_COMPILE_STATUS, &compiled);
#endif
			glAttachShader(m_program, vertShader);

			delete[] fileText;
		}
		GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		{
			char* fileText;

#if defined(__WINDOWS_BUILD__)
			FILE* shaderFile;
			fopen_s(&shaderFile, m_fragFileLocation, "rb");

			fseek(shaderFile, 0, SEEK_END);
			int fileLength = ftell(shaderFile);
			fseek(shaderFile, 0, SEEK_SET);

			fileText = new char[fileLength + 1];
			fread(fileText, 1, fileLength, shaderFile);
			fileText[fileLength] = 0;

			fclose(shaderFile);
#elif defined(__ANDROID_BUILD__)
			AAssetManager* pAssetManager = g_pAndroidApp->activity->assetManager;

			AAsset* asset = AAssetManager_open(pAssetManager, m_fragFileLocation, AASSET_MODE_STREAMING);
			if (asset == 0)
				return;

			if (asset)
			{
				int size = AAsset_seek(asset, 0, SEEK_END);
				AAsset_seek(asset, 0, SEEK_SET);

				fileText = new char[size + 1];
				AAsset_read(asset, fileText, size);
				fileText[size] = 0;

				AAsset_close(asset);
			}
#endif
			const char* strings[] = { "precision highp float;", fileText };
			glShaderSource(fragShader, 2, strings, NULL);
			glCompileShader(fragShader);
			glAttachShader(m_program, fragShader);

			delete[] fileText;
		}

		//TODO: only once(either here or model)
		GLint aPositionIndex = 0;
		GLint aColorIndex = 1;
		GLint aUVIndex = 2;

		glBindAttribLocation(m_program, aPositionIndex, "a_Position");
		glBindAttribLocation(m_program, aColorIndex, "a_Color");
		glBindAttribLocation(m_program, aUVIndex, "a_UV");

		glLinkProgram(m_program);
	}

	void ShaderProgram::CreateProgram(char* aVertFileLocation, char* aFragFileLocation)
	{
		m_identifier = new char[255];

#ifdef  WIN32
		strcpy_s(m_identifier, 255, "SHADER");
		strcat_s(m_identifier, 255, aVertFileLocation);
		strcat_s(m_identifier, 255, aFragFileLocation);
#else
		strcpy(m_identifier, "SHADER");
		strcat(m_identifier, aVertFileLocation);
		strcat(m_identifier, aFragFileLocation);
#endif

		if (Resource::GetResource(m_identifier) != nullptr)
		{
			m_original = (ShaderProgram*)Resource::GetResource(m_identifier);
			return;
		}

		Resource::AddResource(m_identifier, this);
		m_original = this;

		m_vertFileLocation = new char[strlen(aVertFileLocation)];
		m_fragFileLocation = new char[strlen(aFragFileLocation)];

		//TODO:Write function for this
#ifdef  WIN32
		strcpy_s(m_vertFileLocation, strlen(aVertFileLocation) + 1, aVertFileLocation);
		strcpy_s(m_fragFileLocation, strlen(aFragFileLocation) + 1, aFragFileLocation);
#else
		strcpy(m_vertFileLocation, aVertFileLocation);
		strcpy(m_fragFileLocation, aFragFileLocation);
#endif //  WIN32
	}

	void ShaderProgram::AddUniformRequirement(ShaderUniforms requirement)
	{
		if (m_original != this)
			return;

		m_uniformsRequired.push_back(requirement);
	}

	void ShaderProgram::RemoveUniformRequirement(ShaderUniforms requirement)
	{
		if (m_original != this)
			return;

		for (std::vector<ShaderUniforms>::iterator it = m_uniformsRequired.begin(); it != m_uniformsRequired.end();)
		{
			if (*it == requirement)
			{
				it = m_uniformsRequired.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
}