#pragma once
#include "gameObject.h"

#include "gameObject.h"

/*
* The Game class is the base class for the class you create for your game
*/
class Game
{
public:
	Game() {}
	virtual ~Game() {}

	/*
	* Initialize whatever you want here
	*/
	virtual void Init() {}

	/*
	* Runs all keyboard and mouse events
	*/
	virtual void Input(float delta);

	/*
	* Updates at your game's desired frame rate
	*/
	virtual void Update(float delta);

	/*
	* Gets the root game object of the scenegraph
	* @return Root game object
	*/
	inline GameObject& GetRoot() { return m_root; }
protected:
	/*
	* Adds objects to the scene graph
	* @param child GameObject to add to the scene
	*/
	void AddToScene(GameObject& child) { m_root.AddChild(child); }
private:
	Game(Game& game) {}
	void operator=(Game& game) {}

	GameObject m_root;
};