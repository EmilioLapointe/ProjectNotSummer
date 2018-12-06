#ifndef __TLGE__MODEL_H__
#define __TLGE__MODEL_H__

namespace TLGE
{
	/**************************************************************************
	* Model is a class that points to a mesh and a shader and holds various   *
	* pieces of information for that shader                                   *
	*                                                                         *
	* Important notes:                                                        *
	*	-Model is tied to OpenGL ES 2.0 and must be changed if the graphics   *
	*		library is changed                                                *
	***************************************************************************/
	class Model : public Component
	{
	public:
		//Object in charge is set on creation and cannot be changed
		Model(GameObject* objectInCharge);
		virtual ~Model();

		//Regular update.
		void Update(float deltaTime);
		//Loads lost or unloaded information(usefull for phone applications)
		void Load();

		//Called by the graphics system to draw the model onto the screen
		virtual void Draw();

		//Sets a value for that respective uniform
		void SetModelUniform(ShaderUniforms uniform, float value);

		//Getters
		Mesh* GetMesh() { return m_mesh; }
		ShaderProgram* GetProgram() { return m_program; }
		Texture* GetTexture() { return m_texture; }
		bool GetVisible() { return m_visible; }

		//Setters
		void SetMesh(Mesh* mesh) { m_mesh = mesh; }
		void SetProgram(ShaderProgram* program) { m_program = program; }
		void SetTexture(Texture* texture) { m_texture = texture; }
		void SetVisible(bool visibility) { m_visible = visibility; }

	protected:
		Mesh* m_mesh;
		ShaderProgram* m_program;
		Texture* m_texture;
		std::map<ShaderUniforms, float> m_modelInfo;

		bool m_visible;
	};
}

#endif