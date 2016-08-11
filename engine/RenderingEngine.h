#pragma once

#include "camera.h"
class GameObject;

/* 
* This is the current OpenGL Renderer
*/
class RenderingEngine
{
public:
	/*
	* Sets up the camera and initializes OpenGL
	*/
	RenderingEngine();

	/*
	* Handles all keyboard and mouse events
	* @param delta Time between frames
	*/
	void Input(float delta);

	/*
	* Renders a GameObject
	* @param object GameObject to render
	*/
	void Render(GameObject* object);

	/*
	* Returns the main camera in the scene
	* @return The main camera
	*/
	inline Camera& GetMainCamera() { return m_mainCamera; }

	/*
	* Sets the main camera in the scene
	* @param camera The new main camera
	*/
	inline void SetMainCamera(const Camera& camera) { m_mainCamera = camera; }

	virtual ~RenderingEngine();
protected:
private:
	void operator=(const RenderingEngine& other) {}

	/* The camera currently viewing the rendered scene */
	Camera m_mainCamera;
};