#pragma once

#include "Transform.h"

class RenderingEngine;
/*
* Components of a Game Object with their own logic in the game's Update loop
*/
class GameComponent
{
public:
	virtual ~GameComponent() {}

	/*
	* Handles all keyboard and mouse input events
	* @param transform Transform of the GameObject
	* @param delta Time between frames
	*/
	virtual void Input(const Transform& transform, float delta) {}

	/*
	* Updates game logic at your game's desired frame rate
	* @param transform Transform of the GameObject
	* @param delta Time between frames
	*/
	virtual void Update(const Transform& transform, float delta) {}

	/*
	* Renders the GameObject
	* @param transform Transform of the GameObject
	* @param shader Shader program being used to render
	* @param renderingEngine The renderer
	*/
	virtual void Render(const Transform& transform, RenderingEngine* renderingEngine) {}
};
