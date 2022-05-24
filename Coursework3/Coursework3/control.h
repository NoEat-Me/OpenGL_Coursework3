#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include "camera.h"

void processKeyboard(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && pedestal_height < 0.25f)
	{
		lightColour = glm::vec3(1.0f, 0.6f, 0.6f);
	}
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && pedestal_height < 0.25f)
	{
		lightColour = glm::vec3(0.6f, 1.0f, 0.6f);
	}
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && pedestal_height < 0.25f)
	{
		lightColour = glm::vec3(0.4f, 0.4f, 1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS && pedestal_height < 0.25f)
	{
		lightColour = glm::vec3(1.0f, 1.0f, 1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && pedestal_height < 0.25f)
	{
		pedestal_height += 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS && pedestal_height > -0.025f)
	{
		pedestal_height -= 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS)
	{
		lightPos = Camera.Position;
	}
	bool cam_changed = false;
	float x = 0.0f, y = 0.0f;
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		Camera.MovementSpeed = .5f;
	}
	else
	{
		Camera.MovementSpeed = .2f;
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		x = 0.f;
		y = -1.f;
		cam_changed = true;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		x = 0.f;
		y = 1.f;
		cam_changed = true;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		x = -1.f;
		y = 0.f;
		cam_changed = true;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		x = 1.f;
		y = 0.f;
		cam_changed = true;
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		cam_dist -= 0.1 * Camera.MovementSpeed;
		cam_changed = true;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		cam_dist += 0.1 * Camera.MovementSpeed;
		cam_changed = true;
	}
	if (cam_changed)
	{
		MoveAndOrientCamera(Camera, glm::vec3(0, 0, 0), cam_dist, x, y);
	}
}