#ifndef __TLGE__TEXTURE_H__
#define __TLGE__TEXTURE_H__

namespace TLGE
{
	/**************************************************************************
	* Texture is a class that stores pixel information and a texture handle   *
	* for use in openGL shaders                                               *
	*                                                                         *
	* Important notes:                                                        *
	*	-Texture is tied to OpenGL ES 2.0 and must be changed if the graphics *
	*		library is changed                                                *
	*	-Texture implements the Resource interface and must be able to reload *
	***************************************************************************/
	class Texture : public Resource
	{
	public:
		Texture();
		virtual ~Texture();

		//Loads or reloads the mesh using the vertex array
		void Load();

		//Fills in information for texture creation
		void CreateTexture(char* textureFileLocation);

		//Getters
		GLuint GetTextureHandle() { return m_original->m_textureHandle; }

	private:
		GLuint m_textureHandle;
		char* m_textureLocation;

		Texture* m_original;
	};
}

#endif