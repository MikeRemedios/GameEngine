#pragma once

#include "Shader.h"
#include <glm\glm.hpp>
#include "Util.h"

/*
* SkyboxShader is a default unlit shader program to be used
*/
class SkyboxShader : public Shader
{
public:


	static SkyboxShader* getInstance()
	{
		static SkyboxShader instance;
		return &instance;
	}

	virtual void UpdateUniforms(const Transform& transform, const Material& material, RenderingEngine* renderingEngine);

protected:
private:
	SkyboxShader();

	SkyboxShader(SkyboxShader const&) {}
	void operator=(SkyboxShader const&) {}

};

