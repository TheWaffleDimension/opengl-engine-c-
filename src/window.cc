/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * window.cc
 * Copyright (C) 2018 Mason Harris <thewaffledimension@gmail.com>
 *
 * sparky_engine is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * sparky_engine is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "window.h"

namespace Core { namespace Graphics {
	Window::Window(const char *title, int width, int height) {
		m_title = title;
		m_width = width;
		m_height = height;
		
		if (!init())
			glfwTerminate();
	}
	 
	Window::~Window() {
		glfwTerminate();
	}

	bool Window::init() { // Initialize GLFW and GLEW
		if (!glfwInit()) {
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// 4x antialiasing
    	glfwWindowHint(GLFW_SAMPLES, 4);
		
		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
		if (!m_window) {
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, this);
		glfwSetWindowSizeCallback(m_window, onWindowResize);
		glfwSetKeyCallback(m_window, onKeyChange);
		glfwSetMouseButtonCallback(m_window, onMouseChange);
		glfwSetCursorPosCallback(m_window, onMouseMove);

		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		if (glewInit() != GLEW_OK) {
			std::cout << "Failed to initialize GLEW!" << std::endl;
			return false;
		}

		return true;
	}

	void Window::clear() const { // Clear the color and depth buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	 
	void Window::update() { // Update the window
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	bool Window::closed() const { // Return if the window should close
		return glfwWindowShouldClose(m_window) == 1;
	}

	// Get width and height
	inline int Window::getWidth() const { return m_width; }
	inline int Window::getHeight() const { return m_height; }
	
	void Window::onWindowResize(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Window::onKeyChange(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Input::Keyboard::getInstance()
			.setKeyState(key, action != GLFW_RELEASE);
	}

	void Window::onMouseMove(GLFWwindow* window, double mx, double my) {
		Input::Mouse& mouse = Input::Mouse::getInstance();
		mouse.setX(mx);
		mouse.setY(my);
	}

	void Window::onMouseChange(GLFWwindow* window, int button, int action, int mods) {
		Input::Mouse::getInstance()
			.setButtonState(button, action != GLFW_RELEASE);
	}
 } }

