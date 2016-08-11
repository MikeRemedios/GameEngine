#pragma once

#include "Game.h"
#include <string>
#include "RenderingEngine.h"

/*
* The Engine class initializes the game engine, creates the window and runs the game loop
*/
class Engine
{
public:

	/*
	* @param width Sets width of the window
	* @param height Sets height of the window
	* @param frameRate Desired framerate of the game
	* @param game The game you're running
	*/
	Engine(int width, int height, double frameRate, Game* game);
	virtual ~Engine();

	/*
	* Creates window with desired dimensions
	* @param title Title of window
	*/
	void createWindow(const std::string& title);

	/*
	* Sets isRunning to true
	*/
	void start();

	/*
	* Sets isRunning to false if not already false
	*/
	void stop();

private:

	Engine(const Engine& other) {}
	void operator=(const Engine& other) {}

	/*
	* Runs the game loop
	*/
	void Run();

	/* True when game is started, false when game is attempted to be closed */
	bool m_isRunning;
	/* Width of the window */
	int m_width;
	/* Height of the window */
	int m_height;
	/* Time a frame should take in seconds */
	double m_frameTime;
	/* Running game */
	Game* m_game;

	/* The rendering engine using OpenGL */
	RenderingEngine* m_renderingEngine;
};

