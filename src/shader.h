/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * shader.h
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

#ifndef _SHADER_H_
#define _SHADER_H_

#include <GL/glew.h>
#include <string>
#include <vector>
#include <iostream>
#include "fileutils.h"

namespace Core { namespace Graphics {
	class Shader {
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void enable() const;
		void disable() const;
	protected:

	private:
		// Functions
		GLuint load();

		// Vars
		const char* m_vertPath;
		const char* m_fragPath;
		GLuint m_shaderID;
	};
} }

#endif // _SHADER_H_

