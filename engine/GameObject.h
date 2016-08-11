#pragma once

#include <vector>
#include "Transform.h"
#include "GameComponent.h"
#include "BasicShader.h"

class RenderingEngine;

/* The GameObject is the base class of all objects to be rendered in the scene, or objects that have logic */
class GameObject
{
public:
	GameObject() {}
	/*
	* Adds child to current GameObject
	* @param child New GameObject to be added as child
	*/
	void AddChild(GameObject& child);

	/*
	* Adds component to current GameObject
	* @param component Component to be added to GameObject
	*/
	void AddComponent(GameComponent* component);

	/*
	* Handles all keyboard and mouse events
	* @param delta Time between frames
	*/
	void Input(float delta);

	/*
	* Updates logic at desired frame rate
	* @param delta Time between frames
	*/
	void Update(float delta);

	/*
	* Renders the GameObject in the scene
	* @param shader Shader program used to render
	* @param renderingEngine The renderer
	*/
	void Render(RenderingEngine* renderingEngine);

	/*
	* Gets transform of the GameObject
	* @return Transform of the GameObject
	*/
	inline Transform& GetTransform() { return m_transform; }
protected:
private:
	/* Vector list of all children of the GameObject */
	std::vector<GameObject*> m_children;

	/* Vector list of all components of the GameObject */
	std::vector<GameComponent*> m_components;

	/* Transform of the GameObject */
	Transform m_transform;
};