#include "Camera.h"
#include <glm/gtx/transform.hpp>


Camera::Camera() :
	viewDirection(0.0f, 0.0f, -1.0f),
	UP(0.0f, 1.0f, 0.0f)
{

}

void Camera::mouseUpdate(const glm::vec2& newMousePosition)
{
	glm::vec2 mouseDelta = newMousePosition - oldMousePosition;
	if (glm::length(mouseDelta) > 20.0f)
	{
		oldMousePosition = newMousePosition;
		return;
	}
	
	glm::vec3 toRotateAround = glm::cross(viewDirection, UP);
	glm::mat4 rotator = glm::rotate(-mouseDelta.x * 0.5f, UP) * glm::rotate(-mouseDelta.y * 0.5f, toRotateAround);
	viewDirection = glm::mat3(rotator) * viewDirection;

	oldMousePosition = newMousePosition;

}

glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position, position + viewDirection, UP);
}

const float MOVEMENT_SPEED = 0.1f;

void Camera::moveForward()
{
	position += MOVEMENT_SPEED * viewDirection;
}
void Camera::moveBackward()
{
	position += -MOVEMENT_SPEED * viewDirection;
}
void Camera::moveLeft()
{
	glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
	position += MOVEMENT_SPEED * strafeDirection;
}
void Camera::moveRight()
{
	glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
	position += -MOVEMENT_SPEED * strafeDirection;
}
void Camera::moveUp()
{
	position += MOVEMENT_SPEED * UP;
}
void Camera::moveDown()
{
	position += -MOVEMENT_SPEED * UP;
}

