#ifndef __TLGE__SHADER_PROGRAM_H__
#define __TLGE__SHADER_PROGRAM_H__

namespace TLGE
{
	//TODO:add error checking here and in window creation

	/**************************************************************************
	* ShaderProgram is a class that stores shader information for drawing     *
	* using openGL                                                            *
	*                                                                         *
	* Important notes:                                                        *
	*	-ShaderProgram is tied to OpenGL ES 2.0 and must be changed if the    *
	*		graphics library is changed                                       *
	*	-ShaderProgram implements the Resource interface and must be able to  *
	*		reload                                                            *
	***************************************************************************/
	class ShaderProgram : public Resource
	{
	public:
		ShaderProgram();
		virtual ~ShaderProgram();

		//Loads or reloads the mesh using the vertex array
		void Load();

		//TODO: replace with good functions to create program and make load efficient
		void CreateProgram(char* vertFileLocation, char* fragFileLocation);

		//Adds a requirement for the model to fill
		void AddUniformRequirement(ShaderUniforms requirement);

		//Removes a requirement for the model to fill
		void RemoveUniformRequirement(ShaderUniforms requirement);

		//Getters
		GLuint GetProgram() { return m_original->m_program; }
		std::vector<ShaderUniforms>* GetUniformsRequired() { return &(m_original->m_uniformsRequired); };

	private:
		GLuint m_program;

		char* m_vertFileLocation;
		char* m_fragFileLocation;

		std::vector<ShaderUniforms> m_uniformsRequired;

		ShaderProgram* m_original;
	};
}

#endif