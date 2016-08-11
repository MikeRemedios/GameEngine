#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>



/*
* The camera class is a camera able to be moved around to change view of the world
*/
class Camera
{
public:

	Camera()	
	{
		m_pos = glm::vec3(0, 0, 0);
		m_forward = glm::vec3(0, 0, 1);
		m_up = glm::vec3(0, 1, 0);
		m_projection = glm::perspective(glm::radians(70.0f), (float)1080/720, 0.01f, 1000.0f);
	}

	/*
	* Sets up the perspective view matrix
	* @param fov Angle that the camera is able to see
	* @param aspect Aspect ratio of the camera view
	* @param zNear Z-axis position of the near plane
	* @param zFar Z-axis position of the far plane
	*/
	Camera(float fov, float aspect, float zNear, float zFar);

	/*
	* Moves the camera with input
	* @param delta Time between frames
	*/
	void input(float delta);

	// Moves the camera
	void move(const glm::vec3& direction, float amt);
	
	// rotates the camera
	void rotateY(float angle);
	void rotateX(float angle);

	/*
	* Matrix passed to the shader that moves objects based on the camera's location
	* @return Perspective view matrix sent to the shader
	*/
	glm::mat4 GetViewProjection() const;

	/*
	* Gets position of the camera
	* @return Position of camera
	*/
	glm::vec3& getPosition();

	/*
	* Gets forward vector of the camera
	* @return Forward vector of camera
	*/
	glm::vec3& getForward();

	/*
	* Gets up vector of the camera
	* @return Up vector of camera
	*/
	glm::vec3& getUp();

	/*
	* Gets left vector of the camera
	* @return Left vector of camera
	*/
	glm::vec3 getLeft() const;

	/*
	* Gets right vector of the camera
	* @return Right vector of camera
	*/
	glm::vec3 getRight() const;

	/*
	* Sets position of camera
	* @param pos New position of camera
	*/
	void setPosition(const glm::vec3& pos);

	/*
	* Sets forward vector of camera
	* @param pos New forward vector of camera
	*/
	void setForward(const glm::vec3& forward);

	/*
	* Sets up vector of camera
	* @param pos New up vector of camera
	*/
	void setUp(const glm::vec3& up);
private:

	glm::vec3 m_pos;
	glm::vec3 m_forward;
	glm::vec3 m_up;
	glm::mat4 m_projection;
};

