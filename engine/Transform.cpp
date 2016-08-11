#include "Transform.h"
#include "Util.h"
#include <math.h>
#include <glm\gtx\transform.hpp>
#include <iostream>

Transform::Transform(glm::vec3 pos, glm::quat rot, glm::vec3 scale) :
	m_position(pos),
	m_rotation(rot),
	m_scale(scale) { }

glm::mat4 Transform::getTransform() const
{
	glm::mat4 translationMatrix = glm::translate(glm::mat4(), m_position);
	glm::mat4 rotationMatrix = glm::mat4_cast(glm::normalize(m_rotation));
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(), m_scale);

	return m_parentMatrix * translationMatrix * rotationMatrix * scaleMatrix;
}

glm::mat4 Transform::getParentTransform() const
{
	return m_parent->getTransform();
}

bool Transform::hasChanged()
{
	if (m_position != m_oldPosition)
		return true;
	if (m_rotation != m_oldRotation)
		return true;
	if (m_scale != m_oldScale)
		return true;

	m_oldPosition = m_position;
	m_oldRotation = m_rotation;
	m_oldScale = m_scale;

	return false;
}