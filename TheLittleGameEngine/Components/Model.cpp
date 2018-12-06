#include "EnginePCH.h"

namespace TLGE
{
	Model::Model(GameObject* aObjectInCharge):
		Component(aObjectInCharge),
		m_visible(true)
	{
		aObjectInCharge->RequireComponent<Transform>();
	}
	Model::~Model()
	{
		//nothing to do
	}

	void Model::Update(float deltaTime)
	{

	}
	void Model::Load()
	{
		
	}

	void Model::Draw()
	{
		if (m_visible == false)
			return;
		//TODO: fix 0 to nullptr
		if (m_mesh == 0)
			return;
		assert(m_mesh->GetVBO() != 0);

		GLuint program = m_program->GetProgram();

		glBindBuffer(GL_ARRAY_BUFFER, m_mesh->GetVBO());
		glUseProgram(program);

		//TODO: only once(either here or shader)
		GLint aPositionIndex = 0;
		GLint aColorIndex = 1;
		GLint aUVIndex = 2;

		glBindAttribLocation(program, aPositionIndex, "a_Position");
		glBindAttribLocation(program, aColorIndex, "a_Color");
		glBindAttribLocation(program, aUVIndex, "a_UV");

		glVertexAttribPointer(aPositionIndex, 3, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (void*)0);
		glEnableVertexAttribArray(aPositionIndex);
		
		glVertexAttribPointer(aColorIndex, 4, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (void*)(3*4));
		glEnableVertexAttribArray(aColorIndex);

		glVertexAttribPointer(aUVIndex, 2, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (void*)(7 * 4));
		glEnableVertexAttribArray(aUVIndex);

		glm::mat4 worldTransform(1.0f);
		Transform* transform = m_objectInCharge->GetComponent<Transform>();
		//TODO: fix 0 to nullptr
		if (transform != 0)
		{
			worldTransform = transform->GetWorldTransform();
		}

		//TODO: GetRid of these
		glm::mat4 viewTransform;
		glm::mat4 projectionTransform;

		std::vector<ShaderUniforms>* requiredUniforms = m_program->GetUniformsRequired();

		for (unsigned int i = 0; i < requiredUniforms->size(); i++)
		{
			GLint uTemp;
			switch ((*requiredUniforms)[i])
			{
			case ShaderUniforms_Texture:
				uTemp = glGetUniformLocation(m_program->GetProgram(), UNIFORM_NAMES[ShaderUniforms_Texture]);

				glActiveTexture(GL_TEXTURE0 + 0);
				glBindTexture(GL_TEXTURE_2D, m_texture->GetTextureHandle());
				glUniform1i(uTemp, 0);
				break;
			case ShaderUniforms_WorldTransform:
				uTemp = glGetUniformLocation(program, UNIFORM_NAMES[ShaderUniforms_WorldTransform]);

				glUniformMatrix4fv(uTemp, 1, GL_FALSE, &(worldTransform[0][0]));
				break;
			case ShaderUniforms_ViewTransform:
				uTemp = glGetUniformLocation(program, UNIFORM_NAMES[ShaderUniforms_ViewTransform]);
						
				viewTransform = m_objectInCharge->GetScene()->GetSystem<Graphics>()->GetCurrentCamera()->GetViewTransform();

				glUniformMatrix4fv(uTemp, 1, GL_FALSE, &(viewTransform[0][0]));
				break;
			case ShaderUniforms_ProjectionTransform:
				uTemp = glGetUniformLocation(program, UNIFORM_NAMES[ShaderUniforms_ProjectionTransform]);

				projectionTransform = m_objectInCharge->GetScene()->GetSystem<Graphics>()->GetCurrentCamera()->GetProjectionTransform();
						
				glUniformMatrix4fv(uTemp, 1, GL_FALSE, &(projectionTransform[0][0]));
				break;
			default:
				if (m_modelInfo.count((*requiredUniforms)[i]))
				{
					uTemp = glGetUniformLocation(program, UNIFORM_NAMES[(*requiredUniforms)[i]]);
					glUniform1f(uTemp, m_modelInfo[(*requiredUniforms)[i]]);
				}
				break;
			}
		}

		glDrawArrays(GL_TRIANGLES, 0, m_mesh->GetSize() * sizeof(VertexInfo));
	}

	void Model::SetModelUniform(ShaderUniforms uniform, float value)
	{
		m_modelInfo[uniform] = value;
	}
}