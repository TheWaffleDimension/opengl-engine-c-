/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * shader.cpp
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

#include "shader.h"

namespace Core { namespace Graphics {

	Shader::Shader(const char* vertPath, const char* fragPath)
		: m_vertPath(vertPath), m_fragPath(fragPath) {
			m_shaderID = load();
	}

	Shader::~Shader() {
		
	}

	GLuint Shader::load() {
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertContents = Utils::FileUtils::read_file(m_vertPath);
		const char* vertSource = vertContents.c_str();
		std::cout << "Vertex Shader: " << std::endl << vertSource << std::endl;
		std::string fragContents = Utils::FileUtils::read_file(m_fragPath);
		const char* fragSource = fragContents.c_str();
		std::cout << "Fragment Shader: " << std::endl << fragSource << std::endl;

		// VERTEX SHADER //
		
		glShaderSource(vertex, 1, &vertSource, NULL);
		glCompileShader(vertex);

		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		// FRAGMENT SHADER //
		
		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	void Shader::enable() const {
		glUseProgram(m_shaderID);
	}

	void Shader::disable() const {
		glUseProgram(0);
	}
	 
} }

