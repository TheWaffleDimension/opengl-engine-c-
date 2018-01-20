/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2018 TheWaffleDimension <thewaffledimension@gmail.com>
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
#include "input.h"
#include "math.h"
#include "fileutils.h"

int main() {
	using namespace Core;
	using namespace Graphics;
	using namespace Input;
	using namespace Math;
	using namespace Utils;

	std::string file = read_file("test.txt");
	std::cout << file << std::endl;
	system("read -n1 -r -p \"Press any key to continue...\" key");
	return 0;
	
	Window window("Some 3D Engine", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Mat4 position = Mat4::translation(Vec3(2.0f, 3.0f, 4));
	position *= Mat4::identity();

	position.elements[12] = 2.0f;

	Vec4 column = position.columns[3];

	while (!window.closed()) {
		window.clear();
		if (Mouse::getInstance().pressed(GLFW_MOUSE_BUTTON_LEFT)) {
			Mouse mouse = Mouse::getInstance();
			Vec2 mousePos = Vec2(mouse.getX(), mouse.getY());
			std::cout << mousePos << std::endl;
		}
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}
		
	return 0;
}

