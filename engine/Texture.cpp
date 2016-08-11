#include "Texture.h"

#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb\stb_image.h>

Texture* Texture::m_lastBind = 0;

Texture::Texture(const std::string & fileName, GLenum textureTarget, GLfloat filter)
{
	int x, y, numComponents;
	unsigned char* data = stbi_load(("res/textures/" + fileName).c_str(), &x, &y, &numComponents, 4);

	if (data == NULL)
	{
		std::cerr << "Unable to load texture " << fileName << std::endl;
	}

	initTexture(x, y, data, textureTarget, filter);
	stbi_image_free(data);
}

Texture::Texture(const std::string &filenamePosX, const std::string &filenameNegX,
	const std::string &filenamePosY, const std::string &filenameNegY,
	const std::string &filenamePosZ, const std::string &filenameNegZ)
{
	int x, y, numComponents;
	unsigned char* data[6];
	data[0] = stbi_load(("res/textures/" + filenamePosX).c_str(), &x, &y, &numComponents, 4);
	data[1] = stbi_load(("res/textures/" + filenameNegX).c_str(), &x, &y, &numComponents, 4);
	data[2] = stbi_load(("res/textures/" + filenamePosY).c_str(), &x, &y, &numComponents, 4);
	data[3] = stbi_load(("res/textures/" + filenameNegY).c_str(), &x, &y, &numComponents, 4);
	data[4] = stbi_load(("res/textures/" + filenamePosZ).c_str(), &x, &y, &numComponents, 4);
	data[5] = stbi_load(("res/textures/" + filenameNegZ).c_str(), &x, &y, &numComponents, 4);

	for (int i = 0; i < 6; ++i)
	{
		if (data[i] == NULL)
		{
			switch (i)
			{
			case 0:
				std::cerr << "Unable to load cube map texture " << filenamePosX << std::endl;
				break;
			case 1:
				std::cerr << "Unable to load cube map texture " << filenameNegX << std::endl;
				break;
			case 2:
				std::cerr << "Unable to load cube map texture " << filenamePosY << std::endl;
				break;
			case 3:
				std::cerr << "Unable to load cube map texture " << filenameNegY << std::endl;
				break;
			case 4:
				std::cerr << "Unable to load cube map texture " << filenamePosZ << std::endl;
				break;
			case 5:
				std::cerr << "Unable to load cube map texture " << filenameNegZ << std::endl;
				break;
			default:
				break;
			}
			
		}
	}
	
	loadCubeMap(data, x, y);
	for (auto e : data)
		stbi_image_free(e);
		
}

Texture::Texture(int width, int height, unsigned char * data, GLenum textureTarget, GLfloat filter)
{
	initTexture(width, height, data, textureTarget, filter);
}

Texture::~Texture()
{
	if (m_freeTexture) { glDeleteTextures(1, &m_textureID); }
}

void Texture::bind(GLenum textureUnit)
{
	if (m_lastBind != this)
	{
		glActiveTexture(textureUnit);
		glBindTexture(m_textureTarget, m_textureID);
		m_lastBind = this;
	}
}

Texture::Texture(Texture & texture)
{
	m_textureTarget = texture.m_textureTarget;
	m_textureID = texture.m_textureID;
	m_freeTexture = true;
	texture.m_freeTexture = false;
}

void Texture::operator=(Texture & texture)
{
	m_textureTarget = texture.m_textureTarget;
	m_textureID = texture.m_textureID;
	m_freeTexture = true;
	texture.m_freeTexture = false;
}

void Texture::initTexture(int width, int height, unsigned char * data, GLenum textureTarget, GLfloat filter)
{
	m_textureTarget = textureTarget;
	m_freeTexture = true;

	if (width > 0 && height > 0 && data != 0)
	{
		glGenTextures(1, &m_textureID);
		glBindTexture(textureTarget, m_textureID);
		glTexParameterf(textureTarget, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameterf(textureTarget, GL_TEXTURE_MAG_FILTER, filter);
		glTexImage2D(textureTarget, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else {
		m_textureID = 0;
	}
}

void Texture::loadCubeMap(unsigned char* data[6], int width, int height)
{
	glCullFace(GL_FRONT);
	m_textureTarget = GL_TEXTURE_CUBE_MAP;

	if (width > 0 && height > 0 && (data[0] != 0 || data[1] != 0 || 
		data[2] != 0 || data[3] != 0 || data[4] != 0 || 
		data[5] != 0))
	{
		glGenTextures(1, &m_textureID);

		glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); 
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); 
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		for (size_t i = 0; i < 6; ++i)
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data[i]);
		
	}
	else {
		m_textureID = 0;
	}
}

