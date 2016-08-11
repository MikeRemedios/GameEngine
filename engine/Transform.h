#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Camera.h"

/*
* The Transform class holds Position, Rotation, and Scale of a GameObject
*/
class Transform
{
public:
	/*
	* Sets the position to the origin, no rotation and scale of 1
	* @param pos Position relative to parent (world big daddy)
	* @param rot Local rotation
	* @param scale Local scale
	*/
	Transform(glm::vec3 pos = glm::vec3(0, 0, 0), glm::quat rot = glm::quat(0, 0, 0, 0), glm::vec3 scale = glm::vec3(1,1,1));

	/*
	* Returns transform of the object
	* @return Transform of object
	*/
	glm::mat4 getTransform() const;

	void setTransform(glm::vec3 pos, glm::quat rot, glm::vec3 scale);

	/*
	* Returns transform of the parent object
	* @return Transform of parent object
	*/
	glm::mat4 getParentTransform() const;

	void setParent(Transform& parent) 
	{
		m_parent = &parent; 
		m_parentMatrix = m_parent->getTransform();
	}

	void setParentTransform()
	{
		m_parentMatrix = m_parent->getTransform();
	}

	/*
	* Sets position of object
	* @param trans New position of object
	*/
	void setPosition(glm::vec3 pos) { m_position = pos; }

	/*
	* Sets rotation of object
	* @param trans New rotation of object
	*/
	void setRotation(glm::quat rot) { m_rotation = rot; }

	/*
	* Sets scale of object
	* @param trans New scale of object
	*/
	void setScale(glm::vec3 sca) { m_scale = sca; }

	/*
	* Returns position of the object
	* @return Position of object
	*/
	glm::vec3 getPosition() { return m_position; }

	/*
	* Returns Scale of the object
	* @return Scale of object
	*/
	glm::vec3 getScale() { return m_scale; }

	/*
	* Returns Rotation of the object
	* @return Rotation of object
	*/
	glm::quat getRotation() { return m_rotation; }

	bool hasChanged();
private:
	/* Position of object */
	glm::vec3 m_position = glm::vec3(0.0f,0.0f,10.0f);
	/* Rotation of object */
	glm::quat m_rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
	/* Scale of object */
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);

	/* Position of object */
	glm::vec3 m_oldPosition = glm::vec3(0.0f, 0.0f, 10.0f);
	/* Rotation of object */
	glm::quat m_oldRotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
	/* Scale of object */
	glm::vec3 m_oldScale = glm::vec3(1.0f, 1.0f, 1.0f);

	glm::mat4 m_parentMatrix = glm::mat4();
	Transform* m_parent;
};