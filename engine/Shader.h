#pragma once

#include <unordered_map>
#include <string>
#include <glm\glm.hpp>
#include "Material.h"
#include "RenderingEngine.h"
#include "Transform.h"

/*
* The Shader class contains all functions necessary to set up a shader program to be used for rendering
*/
class Shader
{
public:
	Shader();
	~Shader();

	/*
	* Gets the uniform matching string uniform and adds it to an unordered map
	* @param uniform string to match
	*/
	void addUniform(const std::string& uniform);

	/*
	* Opens file, converts to string, and adds it to the program.
	* @param text Filename of the shader file
	*/
	void addVertexShaderFromFile(const std::string& text);

	/**
	* Opens file, converts to string, and adds it to the program.
	* @param text Filename of the shader file
	*/
	void addGeometryShaderFromFile(const std::string& text);

	/*
	* Opens file, converts to string, and adds it to the program.
	* @param text Filename of the shader file
	*/
	void addFragmentShaderFromFile(const std::string& text);

	/*
	* Adds vertex shader to the program
	* @param text Shader program as a string
	*/
	void addVertexShader(const std::string& text);

	/*
	* Adds geometry shader to the program
	* @param text Shader program as a string
	*/
	void addGeometryShader(const std::string& text);

	/*
	* Adds fragment shader to the program
	* @param text Shader program as a string
	*/
	void addFragmentShader(const std::string& text);

	/*
	* Sets the value of the integer uniform variable
	* @param name Key of the uniform in the unordered map
	* @param value New value of the uniform
	*/
	void setUniformi(const std::string& name, int value);

	/*
	* Sets the value of the integer uniform variable
	* @param name Key of the uniform in the unordered map
	* @param value New value of the uniform
	*/
	void setUniformf(const std::string& name, float value);

	/*
	* Sets the value of the integer uniform variable
	* @param name Key of the uniform in the unordered map
	* @param value New value of the uniform
	*/
	void setUniform(const std::string& name, const glm::vec3& value);

	/*
	* Sets the value of the integer uniform variable
	* @param name Key of the uniform in the unordered map
	* @param value New value of the uniform
	*/
	void setUniform(const std::string& name, const glm::mat4& value);

	/*
	* Links the shader program, checks for errors, and uses it for rendering.
	*/
	void compileShader();

	/*
	* Uses program for rendering.
	*/
	void bind();

	/*
	* Updates uniforms based on parameters passed
	* @param transform Transform of the game object
	* @param material Material of the game object
	* @param renderingEngine Current engine used for rendering
	*/
	virtual void UpdateUniforms(const Transform& transform, const Material& material, RenderingEngine* renderingEngine);

private:
	/*
	* Compiles the shader and adds the shader to the program
	* @param text Shader as a string
	* @param type Type of shader to be compiled (GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, GL_GEOMETRY_SHADER)
	*/
	void addProgram(const std::string& text, int type);

	/* The shader program */
	int m_program;

	/* List of uniforms */
	std::unordered_map<std::string, int> m_uniforms;
};