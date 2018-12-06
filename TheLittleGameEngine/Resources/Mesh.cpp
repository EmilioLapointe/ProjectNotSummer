#include "EnginePCH.h"

namespace TLGE
{
	Mesh::Mesh() :
		Resource(),
		m_VBO(0),
		//TODO: fix 0 to nullptr
		m_verts(0),
		m_size(0)
	{
		//nothing to do
	}
	Mesh::~Mesh()
	{
		delete[] m_verts;
	}

	void Mesh::Load()
	{
		glGenBuffers(1, &m_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, m_size * sizeof(VertexInfo), m_verts, GL_STATIC_DRAW);

		delete[] m_verts;
	}

	void Mesh::CreateMesh(VertexInfo* aVerts, unsigned int aSize, char* &name)
	{
		m_identifier = new char[255];

#ifdef  WIN32
		strcpy_s(m_identifier, 255, "MESH");
		strcat_s(m_identifier, 255, name);
#else
		strcpy(m_identifier, "MESH");
		strcat(m_identifier, name);
#endif

		if (Resource::GetResource(m_identifier) != nullptr)
		{
			m_original = (Mesh*)Resource::GetResource(m_identifier);
			return;
		}

		Resource::AddResource(m_identifier, this);
		m_original = this;

		//TODO: fix 0 to nullptr
		if (m_verts != 0)
		{
			delete[] m_verts;
		}
		m_verts = new VertexInfo[aSize];

		for (unsigned int i = 0; i < aSize; i++)
		{
			m_verts[i] = aVerts[i];
		}
		m_size = aSize;
	}

	void Mesh::CreateMeshFromOBJ(char* aFileLocation)
	{
		m_identifier = new char[255];

#ifdef  WIN32
		strcpy_s(m_identifier, 255, "MESH");
		strcat_s(m_identifier, 255, aFileLocation);
#else
		strcpy(m_identifier, "MESH");
		strcat(m_identifier, aFileLocation);
#endif

		if (Resource::GetResource(m_identifier) != nullptr)
		{
			m_original = (Mesh*)Resource::GetResource(m_identifier);
			return;
		}

		Resource::AddResource(m_identifier, this);
		m_original = this;

		long length = 0;
		char* buffer;

#if defined(__WINDOWS_BUILD__)
		FILE* objFile;
		fopen_s(&objFile, aFileLocation, "rb");

		assert(objFile != NULL);

		fseek(objFile, 0, SEEK_END);
		length = ftell(objFile);
		fseek(objFile, 0, SEEK_SET);

		buffer = new char[length + 1];
		fread(buffer, 1, length, objFile);
		buffer[length] = 0;

		fclose(objFile);
#elif defined(__ANDROID_BUILD__)
		AAssetManager* pAssetManager = g_pAndroidApp->activity->assetManager;

		AAsset* asset = AAssetManager_open(pAssetManager, aFileLocation, AASSET_MODE_STREAMING);
		if (asset == 0)
			return;

		if (asset)
		{
			length = AAsset_seek(asset, 0, SEEK_END);
			AAsset_seek(asset, 0, SEEK_SET);

			buffer = new char[length + 1];
			AAsset_read(asset, buffer, length);
			buffer[length] = 0;

			AAsset_close(asset);
		}
#endif
		//////////////////////////////////////////////////////////////////
		if (buffer == 0 || length == 0)
		{
			delete[] buffer;
			assert(false);
		}
#if defined(__WINDOWS_BUILD__)
		char* next_token = 0;
		char* line = strtok_s(buffer, "\n", &next_token);
#elif defined(__ANDROID_BUILD__)
		char* line = strtok(buffer, "\n");
#endif

		std::vector<glm::vec3> positions;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		std::vector<VertexInfo> verts;

		positions.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
		normals.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
		uvs.push_back(glm::vec2(0.0f, 0.0f));

		while (line)
		{
			switch (line[0])
			{
			case 'v':
				float x;
				float y;
				float z;

#if defined(__WINDOWS_BUILD__)
				sscanf_s(line, "%*s %f %f %f", &x, &y, &z);
#elif defined(__ANDROID_BUILD__)
				sscanf(line, "%*s %f %f %f", &x, &y, &z);
#endif

				if (line[1] == 't')
				{
					uvs.push_back(glm::vec2(x, y));
				}
				else if (line[1] == 'n')
				{
					normals.push_back(glm::vec3(x, y, z));
				}
				else
				{
					positions.push_back(glm::vec3(x, y, z));
				}
				break;
			case 'f':
				int face[3][3];
#if defined(__WINDOWS_BUILD__)
				int format = sscanf_s(line, "%*s %i/%i/%i %i/%i/%i %i/%i/%i", &face[0][0], &face[0][1], &face[0][2], &face[1][0], &face[1][1], &face[1][2], &face[2][0], &face[2][1], &face[2][2]);
#elif defined(__ANDROID_BUILD__)
				int format = sscanf(line, "%*s %i/%i/%i %i/%i/%i %i/%i/%i", &face[0][0], &face[0][1], &face[0][2], &face[1][0], &face[1][1], &face[1][2], &face[2][0], &face[2][1], &face[2][2]);
#endif
				if (format != 9)
				{
#if defined(__WINDOWS_BUILD__)
					format = sscanf_s(line, "%*s %i//%i %i//%i %i//%i", &face[0][0], &face[0][2], &face[1][0], &face[1][2], &face[2][0], &face[2][2]);
#elif defined(__ANDROID_BUILD__)
					format = sscanf(line, "%*s %i//%i %i//%i %i//%i", &face[0][0], &face[0][2], &face[1][0], &face[1][2], &face[2][0], &face[2][2]);
#endif
					if (format != 6)
					{
#if defined(__WINDOWS_BUILD__)
						format = sscanf_s(line, "%*s %i/%i %i/%i %i/%i", &face[0][0], &face[0][1], &face[1][0], &face[1][1], &face[2][0], &face[2][1]);
#elif defined(__ANDROID_BUILD__)
						format = sscanf(line, "%*s %i/%i %i/%i %i/%i", &face[0][0], &face[0][1], &face[1][0], &face[1][1], &face[2][0], &face[2][1]);
#endif
						if (format != 6)
						{
#if defined(__WINDOWS_BUILD__)
							format = sscanf_s(line, "%*s %i %i %i", &face[0][0], &face[1][0], &face[2][0]);
#elif defined(__ANDROID_BUILD__)
							format = sscanf(line, "%*s %i %i %i", &face[0][0], &face[1][0], &face[2][0]);
#endif
							face[0][1] = 0;
							face[0][2] = 0;
							face[1][1] = 0;
							face[1][2] = 0;
							face[2][1] = 0;
							face[2][2] = 0;
						}
						else
						{
							face[0][2] = 0;
							face[1][2] = 0;
							face[2][2] = 0;
						}
					}
					else
					{
						face[0][1] = 0;
						face[1][1] = 0;
						face[2][1] = 0;
					}
				}

				for (int i = 2; i >= 0; i--)
				{
					glm::vec3 position = positions[face[i][0]];
					//position.z *= -1;
					glm::vec2 uv = uvs[face[i][1]];
					glm::vec3 normal = normals[face[i][2]];
					//normal.z *= -1;

					VertexInfo vert;
					vert.pos = position;
					vert.uv = uv;
					vert.normal = normal;

					verts.push_back(vert);
				}
				break;
			}
#if defined(__WINDOWS_BUILD__)
			line = strtok_s(0, "\n", &next_token);
#elif defined(__ANDROID_BUILD__)
			line = strtok(0, "\n");
#endif
		}

		delete[] buffer;

		if (m_verts != 0)
		{
			delete[] m_verts;
		}
		m_verts = new VertexInfo[verts.size()];

		for (unsigned int i = 0; i < verts.size(); i++)
		{
			m_verts[i] = verts[i];
		}
		m_size = verts.size();
	}
}