#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <iostream>
#include <math.h>
#include "camera.h"
#include "shader.h"
#include "window.h"
#include "texture.h"
#include "vertices.h"

SCamera Camera;
float crystal_speed = 1.2f;
float light_box_speed = -3.0f;
float pedestal_height = 0.0f;
//glm::vec3 lightPos = glm::vec3(0.0f, 3.0f, -1.0f);
glm::vec3 lightPos = glm::vec3(0.0f, 3.0f, 0.0f);
glm::vec3 lightColour = glm::vec3(1.0f, 1.0f, 1.0f);
//glm::vec3 lightDirection = glm::vec3(0.1f, -.81f, -.61f);
glm::vec3 lightDirection = glm::vec3(0.0f, -1.0f, 0.0f);

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
		lightDirection = Camera.Front;
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

int main()
{
	GLFWwindow* window = CreateGLFWWindow(1600, 1200, "Coursework3");
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	unsigned int shaderProgram = LoadShader("shader.vertex", "shader.fragment");
	InitCamera(Camera, -80, 30);
	MoveAndOrientCamera(Camera, glm::vec3(0, 0, 0), cam_dist, 0.f, 0.f);
	GLuint texture_floor = setup_texture("texture/floor.bmp");
	GLuint texture_wall = setup_texture("texture/wall.bmp");
	GLuint texture_crystal = setup_texture("texture/crystal.bmp");
	GLuint texture_pedestal = setup_texture("texture/crystal.bmp");

	// wall and floor VAO
	unsigned int VAO_Floor;
	glGenVertexArrays(1, &VAO_Floor);
	unsigned int VBO_Floor;
	glGenBuffers(1, &VBO_Floor);
	glBindVertexArray(VAO_Floor);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_Floor);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_Floor), vertices_Floor, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// crystal VAO
	unsigned int VAO_crystal;
	glGenVertexArrays(1, &VAO_crystal);
	unsigned int VBO_crystal;
	glGenBuffers(1, &VBO_crystal);
	glBindVertexArray(VAO_crystal);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_crystal);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_crystal), vertices_crystal, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// pedestal VAO
	unsigned int VAO_pedestal;
	glGenVertexArrays(1, &VAO_pedestal);
	unsigned int VBO_pedestal;
	glGenBuffers(1, &VBO_pedestal);
	glBindVertexArray(VAO_pedestal);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_pedestal);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_pedestal), vertices_pedestal, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//light_box VAO
	unsigned int VAO_light_box;
	glGenVertexArrays(1, &VAO_light_box);
	unsigned int VBO_light_box;
	glGenBuffers(1, &VBO_light_box);
	glBindVertexArray(VAO_light_box);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_light_box);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_light_box), vertices_light_box, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glEnable(GL_DEPTH_TEST);
	glUseProgram(shaderProgram);

	while (!glfwWindowShouldClose(window))
	{
		float light_box_movement = sin(glfwGetTime()*10);

		processKeyboard(window);

		glClearColor(.5f, .5f, .5f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glUniform3f(glGetUniformLocation(shaderProgram, "lightDirection"), lightDirection.x, lightDirection.y, lightDirection.z);
		glUniform3f(glGetUniformLocation(shaderProgram, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
		glUniform3f(glGetUniformLocation(shaderProgram, "lightColour"), lightColour.x, lightColour.y, lightColour.z);
		glUniform3f(glGetUniformLocation(shaderProgram, "camPos"), Camera.Position.x, Camera.Position.y, Camera.Position.z);


		glm::mat4 view = glm::mat4(1.f);
		view = glm::lookAt(Camera.Position, Camera.Position + Camera.Front, Camera.Up);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

		glm::mat4 projection = glm::mat4(1.f);
		projection = glm::perspective(glm::radians(45.f), (float)800 / (float)600, .01f, 100.f);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		// draw floor
		glm::mat4 model = glm::mat4(1.f);
		model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.f, 0.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glBindTexture(GL_TEXTURE_2D, texture_floor);
		glBindVertexArray(VAO_Floor);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// draw wall
		glBindTexture(GL_TEXTURE_2D, texture_wall);
		glBindVertexArray(VAO_Floor);

		model = glm::mat4(1.f);
		model = glm::translate(model, glm::vec3(0.f, 1.f, 1.f));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.f);
		model = glm::translate(model, glm::vec3(-1.f, 1.f, 0.f));
		model = glm::rotate(model, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.f);
		model = glm::translate(model, glm::vec3(1.f, 1.f, 0.f));
		model = glm::rotate(model, glm::radians(90.f), glm::vec3(0.f, 1.f, 0.f));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//draw crystal
		glBindTexture(GL_TEXTURE_2D, texture_crystal);
		glBindVertexArray(VAO_crystal);

		glm::mat4 model_crystal = glm::mat4(1.f);
		model_crystal = glm::translate(model_crystal, glm::vec3(0.0f, 0.6f, 0.0f));
		model_crystal = glm::rotate
		(
			model_crystal, (float)glfwGetTime() * crystal_speed, glm::vec3(0.0f, 1.0f, 0.0f)
		);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model_crystal));
		glDrawArrays(GL_TRIANGLES, 0, 12);

		for (int a = 0;a < 3;a += 1)
		{
			model_crystal = glm::rotate(model_crystal, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model_crystal));
			glDrawArrays(GL_TRIANGLES, 0, 12);
		}

		//draw pedestal
		glBindTexture(GL_TEXTURE_2D, texture_pedestal);
		glBindVertexArray(VAO_pedestal);
		glm::mat4 model_pedestal = glm::mat4(1.f);
		model_pedestal = glm::translate(model_pedestal, glm::vec3(0.0f, pedestal_height, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model_pedestal));
		glDrawArrays(GL_TRIANGLES, 0, 24);

		for (int a = 0; a < 3;a += 1)
		{
			model_pedestal = glm::rotate(model_pedestal, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model_pedestal));
			glDrawArrays(GL_TRIANGLES, 0, 24);
		}

		//draw light box
		glBindTexture(GL_TEXTURE_2D, texture_pedestal);
		glBindVertexArray(VAO_light_box);
		glm::mat4 model_light_box = glm::mat4(1.f);
		model_light_box = glm::scale(model_light_box, glm::vec3(0.02f, 0.06f, 0.02f));
		model_light_box = glm::rotate(model_light_box, (float)glfwGetTime() * light_box_speed, glm::vec3(0.0f, 1.0f, 0.0f));
		model_light_box = glm::translate(model_light_box, glm::vec3(0.0f, 10.0f + light_box_movement * 2.0f, -20.0f));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model_light_box));
		glDrawArrays(GL_TRIANGLES, 0, 18);
		model_light_box = glm::scale(model_light_box, glm::vec3(1.0f, -1.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model_light_box));
		glDrawArrays(GL_TRIANGLES, 0, 18);

		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
