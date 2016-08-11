#pragma once

#include <GL\glew.h>
#include <string>

/*
* The Texture class creates the texture to wrap around meshes
*/
class Texture
{
public:
	/*
	* Loads and decompresses a texture file to char array to be used by any renderer
	* @param fileName Name of texture file with extension
	* @param textureTarget Type of texture to be created
	* @param filter Algorithm used to scale texture (GL_LINEAR, GL_NEAREST, etc)
	*/
	Texture(const std::string& fileName, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR);

	//for skyboxes
	Texture(const std::string &filenamePosX, const std::string &filenameNegX,
		const std::string &filenamePosY, const std::string &filenameNegY,
		const std::string &filenamePosZ, const std::string &filenameNegZ);
	/*
	* Texture created from raw data
	* @param width Width of texture
	* @param height Height of texture
	* @param data Char array of RGB colors
	* @param textureTarget Location of texture on graphics card
	* @param filter Algorithm used to scale texture (GL_LINEAR, GL_NEAREST, etc)
	*/
	Texture(int width = 0, int height = 0, unsigned char* data = 0, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR);
	~Texture();

	/*
	* Sets active texture and binds it
	* @param Texture unit to make active
	*/
	void bind(GLenum textureUnit = GL_TEXTURE0);
	Texture() { m_freeTexture = false; };
	Texture(Texture& texture);
	void operator= (Texture& texture);
private:
	/* Most recently bound texture. Used to not rebind if already bound */
	static Texture* m_lastBind;

	/* Type of current texture */
	GLenum m_textureTarget;
	/* Name of texture */
	GLuint m_textureID;
	/* If it's free to be deleted */
	bool m_freeTexture;
	
	/*
	* Initializes texture with data
	* @param width Width of texture
	* @param height Height of texture
	* @param data Char array of RGB colors
	* @param textureTarget Location of texture on graphics card
	* @param filter Algorithm used to scale texture (GL_LINEAR, GL_NEAREST, etc)
	*/
	void initTexture(int width, int height, unsigned char* data, GLenum textureTarget, GLfloat filter);
	void loadCubeMap(unsigned char* data[6], int width, int height);
};

