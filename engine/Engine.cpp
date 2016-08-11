#include "Engine.h"
#include "Time.h"
#include "Window.h"
#include "Input.h"
#include "Util.h"

#include <stdio.h>

bool IGNORE_FRAME_CAP = false;

Engine::Engine(int width, int height, double frameRate, Game * game) :
	m_isRunning(false),
	m_width(width),
	m_height(height),
	m_frameTime(1.0 / frameRate),
	m_game(game),
	m_renderingEngine(nullptr) {}

Engine::~Engine()
{
	Window::dispose();
	delete m_renderingEngine;
}

void Engine::createWindow(const std::string & title)
{
	Window::create(m_width, m_height, title);
	m_renderingEngine = new RenderingEngine();
}

void Engine::start()
{
	if (m_isRunning)
		return;

	Run();
}

void Engine::stop()
{
	if (!m_isRunning)
		return;

	m_isRunning = false;
}

void Engine::Run()
{
	m_isRunning = true;

	m_game->Init();

	double lastTime = Time::getTime();
	double unprocessedTime = 0;
	double frameCounter = 0;
	int frames = 0;

	while (m_isRunning)
	{
		bool render = false;

		double startTime = Time::getTime();
		double passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime;
		frameCounter += passedTime;

		if (frameCounter >= 1.0)
		{
			printf("%i\n", frames);
			frames = 0;
			frameCounter = 0;
		}

		while (unprocessedTime > m_frameTime)
		{
			render = true;

			if (Window::isCloseRequested())
			{
				stop();
			}
				
			Input::update();

			m_game->Input(m_frameTime);
			m_renderingEngine->Input(m_frameTime);
			m_game->Update(m_frameTime);
			m_game->GetRoot().Update(m_frameTime);

			unprocessedTime -= m_frameTime;
		}

		if (render || IGNORE_FRAME_CAP)
		{
			m_renderingEngine->Render(&m_game->GetRoot());
			Window::render();
			frames++;
		}
		else
		{
			Util::sleep(1);
		}
	}


}
