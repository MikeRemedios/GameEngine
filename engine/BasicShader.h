#pragma once

#include "Shader.h"
#include <glm\glm.hpp>
#include "Util.h"

/*
* BasicShader is a default unlit shader program to be used
*/
class BasicShader : public Shader
{
public:

	static BasicShader* getInstance()
	{
		static BasicShader instance;
		return &instance;
	}

	virtual void UpdateUniforms(const Transform& transform, const Material& material, RenderingEngine* renderingEngine);

protected:
private:
	BasicShader();

	BasicShader(BasicShader const&) {}
	void operator=(BasicShader const&) {}

};

