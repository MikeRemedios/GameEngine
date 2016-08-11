#pragma once

#include <glm\glm.hpp>

/*
* Vertex struct holds vertex data
*/
struct Vertex
{
	/* Vertex coordinate */
	glm::vec3 pos;
	/* The vertex normal */
	glm::vec3 normal;
	/* Texture coordinate */
	glm::vec2 uv;
	/* Color */
	glm::vec4 color;

	/*
	* Sets up vertex
	* @param pos Vertex Coordinates
	* @param uv Texture Coordinates
	* @param normal Vertex normal
	* @param color Vertex color
	*/
	Vertex(glm::vec3 pos, glm::vec2 uv = glm::vec2(0,0), glm::vec3 normal = glm::vec3(0,0,0), glm::vec4 color = glm::vec4(0,0,0,0))
	{
		this->pos = pos;
		this->uv = uv;
		this->normal = normal;
		this->color = color;
	}
};