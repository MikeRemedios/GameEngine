#include "Camera.h"
#include "Input.h"
#include "Time.h"
#include "Window.h"
#include <glm\gtx\quaternion.hpp>
#include <glm\gtx\transform.hpp>
#include <iostream>
bool mouseLocked = false;

Camera::Camera(float fov, float aspect, float zNear, float zFar) :
	m_pos(glm::vec3(0, 0, -3)),
	m_forward(glm::vec3(0, 0, 1)),
	m_up(glm::vec3(0, 1, 0))
{
	m_projection = glm::perspective(fov, aspect, zNear, zFar);
}

void Camera::input(float delta)
{
	float moveAmount = (float)(5.0f * delta);
	
	float sensitivity = 0.005f;
	float rotationAmount = (float)(delta);

	if (Input::getKey(KEY::KEY_ESCAPE))
	{
		Input::setCursor(true);
		mouseLocked = false;
	}

	if (Input::getKey(KEY::KEY_H))
	{
		m_pos = glm::vec3(0, 0, 0);
	}

	if (mouseLocked)
	{
		glm::vec2 centerPosition = glm::vec2((float)Window::getWidth() / 2.0f, (float)Window::getHeight() / 2.0f);
		glm::vec2 deltaPos = Input::getMousePosition() - centerPosition;

		bool rotX = deltaPos.x != 0;
		bool rotY = deltaPos.y != 0;

		if (rotX)
		{
			rotateX(deltaPos.x * sensitivity);
		}
		if (rotY)
		{
			rotateY(deltaPos.y * sensitivity);
		}

		if (rotY || rotX)
		{
			Input::setMousePosition(centerPosition);
		}
	}

	if (Input::getMouseDown(MOUSE::LEFT_MOUSE))
	{
		glm::vec2 centerPosition = glm::vec2((float)Window::getWidth() / 2.0f, (float)Window::getHeight() / 2.0f);
		Input::setMousePosition(centerPosition);
		Input::setCursor(false);
		mouseLocked = true;
	}
	
	if (Input::getKey(KEY::KEY_W))
	{
		move(getForward(), moveAmount);
	}
	if (Input::getKey(KEY::KEY_S))
	{
		move(getForward(), -moveAmount);
	}
	if (Input::getKey(KEY::KEY_A))
	{
		move(getLeft(), -moveAmount);
	}
	if (Input::getKey(KEY::KEY_D))
	{
		move(getRight(), -moveAmount);
	}
	if (Input::getKey(KEY::KEY_E))
	{
		move(glm::vec3(0, 1, 0), moveAmount);
	}
	if (Input::getKey(KEY::KEY_Q))
	{
		move(glm::vec3(0,1,0), -moveAmount);
	}

}

glm::mat4 Camera::GetViewProjection() const
{
	return m_projection * glm::lookAt(m_pos, m_pos + m_forward, m_up);
}

void Camera::move(const glm::vec3 & direction, float amt)
{
	m_pos += (direction * amt);
}

void Camera::rotateY(float angle)
{
	glm::vec3 hAxis = glm::normalize(glm::cross(glm::vec3(0, 1, 0),m_forward));

	m_forward = glm::normalize(glm::rotate(glm::angleAxis(angle, hAxis), m_forward));
	m_up = glm::normalize(glm::cross(m_forward, hAxis));
}

void Camera::rotateX(float angle)
{
	glm::vec3 hAxis = glm::normalize(glm::cross(glm::vec3(0, 1, 0), m_forward));

	m_forward = glm::normalize(glm::rotate(glm::angleAxis(-angle, m_up), m_forward));
	m_up = glm::normalize(glm::cross(m_forward, hAxis));
}

glm::vec3 & Camera::getPosition()
{
	return m_pos;
}

glm::vec3 & Camera::getForward()
{
	return m_forward;
}

glm::vec3 & Camera::getUp()
{
	return m_up;
}

glm::vec3 Camera::getLeft() const
{
	return glm::normalize(glm::cross(m_forward,m_up));
}

glm::vec3 Camera::getRight() const
{
	return glm::normalize(glm::cross(m_up, m_forward));
}

void Camera::setPosition(const glm::vec3 & pos)
{
	m_pos = pos;
}

void Camera::setForward(const glm::vec3 & forward)
{
	m_forward = forward;
}

void Camera::setUp(const glm::vec3 & up)
{
	m_up = up;
}
