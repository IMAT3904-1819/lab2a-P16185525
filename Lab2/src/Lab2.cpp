// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>


int main(int argc, char* argv[])
{
	// Initialise a window and let GLFW know that it should target opengl version 4.3
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpeningAWindow", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Make this new window our current context, THEN try to initialise GLAD function ptrs
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}

	// Until we receive a message to close the program
	while (!glfwWindowShouldClose(window))
	{
		// Clear the screen to a green colour 
		glClearColor(0.8f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap buffers i.e. draw to screen
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	// Cleanup
	glfwTerminate();
    return 0;
}

