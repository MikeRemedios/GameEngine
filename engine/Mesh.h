#pragma once

#include "vertex.h"
#include "ReferenceCounter.h"
#include <string>
#include <map>

/*
* Holds the mesh data so it can be passed to renderers
*/
class MeshData : public ReferenceCounter
{
public:
	/*
	* Generates buffers and initializes VBO and IBO
	* @param indexSize Length of the index array
	*/
	MeshData(int indexSize);
	virtual ~MeshData();

	/*
	* Returns the vertex buffer object
	* @return The Vertex buffer object
	*/
	inline unsigned int GetVBO() { return m_vbo; }

	/*
	* Returns the Index buffer object
	* @return The Index buffer object
	*/
	inline unsigned int GetIBO() { return m_ibo; }

	/*
	* Returns the length of the index array
	* @return Length of the index array
	*/
	inline int GetSize() { return m_size; }
protected:
private:
	MeshData(MeshData& other) {}
	void operator=(MeshData& other) {}

	/* Vertex buffer object */
	unsigned int m_vbo;

	/* Index buffer object */
	unsigned int m_ibo;

	/* Length of index array */
	int m_size;
};

/*
* The Mesh class creates a drawable mesh to be rendered by the MeshRenderer
*/
class Mesh
{
public:
	/*
	* Creates a mesh from file on drive
	* @param fileName Path to file
	*/
	Mesh(const std::string& fileName);

	/*
	* Creates a mesh from data
	* @param vertices The array of vertices of the object
	* @param vertSize Number of vertices
	* @param indices The array of indices
	* @param indexSize Number of indices
	* @param calcNormals Calculates normals if true
	*/
	Mesh(Vertex* vertices, int vertSize, int* indices, int indexSize, bool calcNormals);
	virtual ~Mesh();

	/*
	* Called by the renderer to draw the mesh
	*/
	void Draw() const;
protected:
private:
	/* Holds all mesh data currently loaded into memory */
	static std::map<std::string, MeshData*> s_resourceMap;

	Mesh(Mesh& mesh) {}
	void operator=(Mesh& mesh) {}

	/*
	* Calculates each polygonal normal
	* @param vertices The array of vertices of the object
	* @param vertSize Number of vertices
	* @param indices The array of indices
	* @param indexSize Number of indices
	*/
	void CalcNormals(Vertex* vertices, int vertSize, int* indices, int indexSize);

	/*
	* Creates a mesh from data, generates the buffers and initializes buffer objects
	* @param vertices The array of vertices of the object
	* @param vertSize Number of vertices
	* @param indices The array of indices
	* @param indexSize Number of indices
	* @param calcNormals Calculates normals if true
	*/
	void InitMesh(Vertex* vertices, int vertSize, int* indices, int indexSize, bool calcNormals = true);
	
	/* Path of mesh file */
	std::string m_fileName;

	/* Vertex and index data */
	MeshData* m_meshData;
};