#include "EnginePCH.h"

using namespace std;

namespace TLGE
{
	Sprite::Sprite(GameObject* aObjectInCharge):
		Model(aObjectInCharge),
		m_size(1.0f),
		//TODO: fix 0 to nullptr
		m_privateMesh(0),
		//TODO: fix 0 to nullptr
		m_privateProgram(0),
		//TODO: fix 0 to nullptr
		m_privateTexture(0)
	{
		//nothing to do
	}
	Sprite::~Sprite()
	{
		//TODO: fix 0 to nullptr
		if (m_mesh != 0)
		{
			delete m_mesh;
		}
		//TODO: fix 0 to nullptr
		if (m_privateProgram != 0)
		{
			delete m_privateProgram;
		}
		//TODO: fix 0 to nullptr
		if (m_privateTexture != 0)
		{
			delete m_privateTexture;
		}
	}

	void Sprite::CreateSprite(const glm::vec2 &aSize, char* aImagePath, char* aVertShaderPath, char* aFragShaderPath)
	{
		m_size.x = (float)aSize.x;
		m_size.y = (float)aSize.y;

		float hSizeX = m_size.x * 0.5f;
		float hSizeY = m_size.y * 0.5f;

		VertexInfo vertices[6];
		vertices[0].pos = glm::vec3(-hSizeX, hSizeY, 0);
		vertices[0].uv = glm::vec2(0.0f, 1.0f);

		vertices[1].pos = glm::vec3(hSizeX, hSizeY, 0);
		vertices[1].uv = glm::vec2(1.0f, 1.0f);

		vertices[2].pos = glm::vec3(-hSizeX, -hSizeY, 0);
		vertices[2].uv = glm::vec2(0.0f, 0.0f);

		vertices[3].pos = glm::vec3(hSizeX, hSizeY, 0);
		vertices[3].uv = glm::vec2(1.0f, 1.0f);

		vertices[4].pos = glm::vec3(hSizeX, -hSizeY, 0);
		vertices[4].uv = glm::vec2(1.0f, 0.0f);

		vertices[5].pos = glm::vec3(-hSizeX, -hSizeY, 0);
		vertices[5].uv = glm::vec2(0.0f, 0.0f);

		//TODO: fix 0 to nullptr
		if (m_privateMesh == 0)
		{
			m_privateMesh = new Mesh();
		}

		char* temp = new char[255];

#ifdef  WIN32
		strcpy_s(temp, 255, to_string(m_size.x).c_str());
		strcat_s(temp, 255, "BY");
		strcat_s(temp, 255, to_string(m_size.y).c_str());
		strcat_s(temp, 255, "RECT");
#else
		stringstream ss;
		ss << m_size.x;
		ss << "BY";
		ss << m_size.y;
		ss << "RECT";

		strcpy(temp, ss.str().c_str());
#endif

		m_privateMesh->CreateMesh(&vertices[0], 6, temp);

		delete[] temp;
		SetMesh(m_privateMesh);

		//TODO: fix 0 to nullptr
		if (m_privateProgram == 0)
		{
			m_privateProgram = new ShaderProgram();
		}
		m_privateProgram->CreateProgram(aVertShaderPath, aFragShaderPath);
		m_privateProgram->AddUniformRequirement(ShaderUniforms_Texture);
		m_privateProgram->AddUniformRequirement(ShaderUniforms_WorldTransform);
		//TODO: Remove these after 3d tests
		m_privateProgram->AddUniformRequirement(ShaderUniforms_ViewTransform);
		m_privateProgram->AddUniformRequirement(ShaderUniforms_ProjectionTransform);
		SetProgram(m_privateProgram);

		//TODO: fix 0 to nullptr
		if (m_privateTexture == 0)
		{
			m_privateTexture = new Texture();
		}
		m_privateTexture->CreateTexture(aImagePath);
		SetTexture(m_privateTexture);
	}
}