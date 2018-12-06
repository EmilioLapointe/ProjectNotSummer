#ifndef __TLGE__OBJModel_H__
#define __TLGE__OBJModel_H__

namespace TLGE
{
	/**************************************************************************
	* OBJModel is a class that is in charge of a model that displays a 3d     *
	* mesh created from the information in an OBJ file.                       *
	*                                                                         *
	* Important notes:                                                        *
	*	-OBJModel simply adds functionality to the model component            *
	***************************************************************************/
	class OBJModel : public Model
	{
	public:
		//TODO::create texture class for use here and add it to the build function

		//Object in charge is set on creation and cannot be changed
		OBJModel(GameObject* objectInCharge);
		virtual ~OBJModel();

		//TODO:make this take in an actual shader not the files...makes no sense
		void CreateOBJ(char* objPath, char* imagePath, char* vertShaderPath, char* fragShaderPath);

	private:
		Mesh* m_privateMesh;
		ShaderProgram* m_privateProgram;
		Texture* m_privateTexture;
	};
}

#endif