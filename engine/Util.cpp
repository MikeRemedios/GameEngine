#include "util.h"
#include <sdl/SDL.h>

void Util::sleep(int milliseconds)
{
	SDL_Delay(milliseconds);
}