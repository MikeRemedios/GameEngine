#pragma once

#include "camera.h"
#include "Window.h"
class GameObject;

/*
* This is the abstract renderer
*/
class AbstractRenderer
{
public:

	AbstractRenderer() {};

	/*
	* Handles all keyboard and mouse events
	* @param delta Time between frames
	*/
	virtual void Input(float delta) = 0;

	/*
	* Renders a GameObject
	* @param object GameObject to render
	*/
	virtual void Render(GameObject* object) = 0;

	/*
	* Returns the main camera in the scene
	* @return The main camera
	*/
	virtual inline Camera& GetMainCamera() = 0;

	/*
	* Sets the main camera in the scene
	* @param camera The new main camera
	*/
	virtual inline void SetMainCamera(const Camera& camera) = 0;
protected:
	/* The camera currently viewing the rendered scene */
	Camera m_mainCamera;
	
};

