#include "Skybox.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb\stb_image.h>


Skybox::Skybox(const std::string &filenamePosX, const std::string &filenameNegX,
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


Skybox::~Skybox()
{
}

void Skybox::loadCubeMap(unsigned char* data[6], int width, int height)
{

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
