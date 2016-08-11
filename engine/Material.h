#pragma once

#include "Texture.h"
#include <glm/glm.hpp>

/* The Material class holds a texture and color */
struct Material
{
	/* Texture of the material */
	Texture* texture;
	/* Color of the material */
	glm::vec3 color;

	/*
	* Set Texture and Color
	* @param texture Texture of material (default NULL)
	* @param color Color of material (default white)
	*/
	Material(Texture* texture = NULL, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f))
	{
		this->texture = texture;
		this->color = color;
	}
};