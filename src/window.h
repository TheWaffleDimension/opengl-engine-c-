/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * window.h
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

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "input.h"

namespace Core { namespace Graphics {
		class Window {
		public:
			Window(const char *name, int width, int height);
		 	~Window();
		 	void update();
		 	void clear() const;
		 	bool closed() const;

		 	inline int getWidth() const;
		 	inline int getHeight() const;
		protected:
			
		private:
		 	// Functions
			bool init();
		 	static void onWindowResize(GLFWwindow *window, int width, int height);
		 	static void onKeyChange(GLFWwindow *window, int key, int scancode, int action, int mods);
		 	static void onMouseMove(GLFWwindow* window, double mx, double my);
		 	static void onMouseChange(GLFWwindow* window, int button, int action, int mods);

		 	// Vars
			const char *m_title;
		 	int m_width, m_height;
		 	GLFWwindow *m_window;
		};
} }

#endif // _WINDOW_H_

