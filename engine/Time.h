#pragma once

#include <sdl/SDL.h>

class Time
{
public:

	/*
	* Returns elapsed time from the start
	* @return Elapsed time
	*/
	static double getTime();

	/*
	* Returns time between frames
	* @return Time between frames
	*/
	static double getDelta();

	/*
	* Sets the time since last frame
	* @param value Time since last frame
	*/
	static void setDelta(double value);
protected:
private:
	static double m_delta;
};