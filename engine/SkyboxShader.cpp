#include "SkyboxShader.h"

SkyboxShader::SkyboxShader()
{
	addVertexShaderFromFile("basicSkybox.vert");
	addFragmentShaderFromFile("basicSkybox.frag");
	compileShader();

	addUniform("transform");
}

static unsigned char whitePixel[] = { 0xFF, 0xFF, 0xFF, 0xFF };

void SkyboxShader::UpdateUniforms(const Transform& transform, const Material& material, RenderingEngine* renderingEngine)
{
	static Texture WHITE = Texture(1, 1, whitePixel);

	if (material.texture != NULL)
		material.texture->bind();
	else
		WHITE.bind();

	glm::mat4 worldMatrix = transform.getTransform();
	glm::mat4 projectedMatrix = renderingEngine->GetMainCamera().GetViewProjection() * worldMatrix;

	setUniform("transform", projectedMatrix);
}