#include "time.h"

double Time::m_delta = 0.0;

double Time::getTime()
{
	return SDL_GetTicks() / 1000.0;
}

double Time::getDelta()
{
	return m_delta;
}

void Time::setDelta(double value)
{
	Time::m_delta = value;
}