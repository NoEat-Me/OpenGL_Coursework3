#pragma once

#include <stdio.h>
#include <glm/glm/glm.hpp>

// variables
float cam_dist = 6.0f;

struct SCamera
{
	enum Camera_Movement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;

	glm::vec3 WorldUp;

	float Yaw;
	float Pitch;

	float MovementSpeed = .2f;
	float MouseSensitivity = 1.f;



};


void InitCamera(SCamera& in, float y, float p)
{
	in.Front = glm::vec3(0.0f, 0.0f, -1.0f);
	in.Position = glm::vec3(0.0f, 0.0f, 0.0f);
	in.Up = glm::vec3(0.0f, 1.0f, 0.0f);
	in.WorldUp = in.Up;
	in.Right = glm::normalize(glm::cross(in.Front, in.WorldUp));

	in.Yaw = y;
	in.Pitch = p;
}


void MoveAndOrientCamera(SCamera& in, glm::vec3 target, float distance, float xoffset, float yoffset)
{
	in.Yaw -= xoffset * in.MovementSpeed;
	in.Pitch -= yoffset * in.MovementSpeed;

	if (in.Pitch > 89.0f)                in.Pitch = 89.0f;
	if (in.Pitch < -89.0f)               in.Pitch = -89.0f;

	in.Position.x = cos(glm::radians(in.Yaw)) * cos(glm::radians(in.Pitch)) * cam_dist;
	in.Position.y = sin(glm::radians(in.Pitch)) * cam_dist;
	in.Position.z = sin(glm::radians(in.Yaw)) * cos(glm::radians(in.Pitch)) * cam_dist;

	in.Front = glm::normalize(target - in.Position);
	in.Right = glm::normalize(glm::cross(in.Front, in.WorldUp));
	in.Up = glm::normalize(glm::cross(in.Right, in.Front));
}


