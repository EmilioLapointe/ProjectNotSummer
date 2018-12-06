#ifndef __TLGE__MESH_H__
#define __TLGE__MESH_H__

namespace TLGE
{
	struct VertexInfo
	{
		glm::vec3 pos = glm::vec3(0.0f);
		glm::vec4 color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
		glm::vec2 uv = glm::vec2(0.0f);
		glm::vec3 normal = glm::vec3(0.0f);
	};

	/**************************************************************************
	* Mesh is a class that stores vertex information for drawing using openGL *
	*                                                                         *
	* Important notes:                                                        *
	*	-Mesh is tied to OpenGL ES 2.0 and must be changed if the graphics    *
	*		library is changed                                                *
	*	-Mesh implements the Resource interface and must be able to reload    *
	***************************************************************************/
	class Mesh: public Resource
	{
	public:
		Mesh();
		virtual ~Mesh();

		//Loads or reloads the mesh using the vertex array
		void Load();

		//TODO: replace with good functions to create meshes
		void CreateMesh(VertexInfo* verts, unsigned int size, char* &name);
		void CreateMeshFromOBJ(char* fileLocation);

		//Getters
		GLuint GetVBO() { return m_original->m_VBO; }
		unsigned int GetSize() { return m_original->m_size; }

	private:
		GLuint m_VBO;
		VertexInfo* m_verts;
		unsigned int m_size;

		Mesh* m_original;
	};
}

#endif
