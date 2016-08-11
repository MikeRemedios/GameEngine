#pragma once

#include <GL\glew.h>
#include <string>

class Skybox
{
private:
	/* Type of current texture */
	GLenum m_textureTarget;
	/* Name of texture */
	GLuint m_textureID;
	/* If it's free to be deleted */
	bool m_freeTexture;
public:
	Skybox(const std::string &filenamePosX, const std::string &filenameNegX,
		const std::string &filenamePosY, const std::string &filenameNegY,
		const std::string &filenamePosZ, const std::string &filenameNegZ);
	~Skybox();

	void loadCubeMap(unsigned char* data[6], int width, int height);
};

