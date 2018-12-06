#include "EnginePCH.h"

namespace TLGE
{
	OBJModel::OBJModel(GameObject* aObjectInCharge) :
		Model(aObjectInCharge),
		//TODO: fix 0 to nullptr
		m_privateMesh(0),
		//TODO: fix 0 to nullptr
		m_privateProgram(0),
		//TODO: fix 0 to nullptr
		m_privateTexture(0)
	{
		//nothing to do
	}
	OBJModel::~OBJModel()
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

	void OBJModel::CreateOBJ(char* aObjPath, char* aImagePath, char* aVertShaderPath, char* aFragShaderPath)
	{
		//TODO: fix 0 to nullptr
		if (m_privateMesh == 0)
		{
			m_privateMesh = new Mesh();
		}
		m_privateMesh->CreateMeshFromOBJ(aObjPath);
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