#ifndef __TLGE__SPRITE_H__
#define __TLGE__SPRITE_H__

namespace TLGE
{
	/**************************************************************************
	* Sprite is a class that is in charge of a model that displays a simple   *
	* png section inside a rectangular flat mesh                              *
	*                                                                         *
	* Important notes:                                                        *
	*	-Sprite simply adds functionality to the model component              *
	***************************************************************************/
	class Sprite : public Model
	{
	public:
		//TODO::create texture class for use here and add it to the build function

		//Object in charge is set on creation and cannot be changed
		Sprite(GameObject* objectInCharge);
		virtual ~Sprite();

		//TODO:make this take in an actual shader not the files...makes no sense
		void CreateSprite(const glm::vec2 &size, char* imagePath, char* vertShaderPath, char* fragShaderPath);

		//Getters
		glm::vec2 GetSize() { return m_size; }

	private:
		glm::vec2 m_size;
		Mesh* m_privateMesh;
		ShaderProgram* m_privateProgram;
		Texture* m_privateTexture;
	};
}

#endif