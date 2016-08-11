#include "renderingEngine.h"
#include "basicShader.h"
#include "Window.h"
#include "gameObject.h"
#include <GL/glew.h>

RenderingEngine::RenderingEngine() :
	m_mainCamera(glm::radians(70.0f), Window::GetAspect(), 0.01f, 1000.0f)
{
	glClearColor(0.f, .7f, 1.f, 1.f);

	//glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_CLAMP);
}

RenderingEngine::~RenderingEngine()
{
	//dtor
}

void RenderingEngine::Input(float delta)
{
	m_mainCamera.input(delta);
}

void RenderingEngine::Render(GameObject* object)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	object->Render(this);
}