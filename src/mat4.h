/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * mat4.h
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

#ifndef _MAT4_H_
#define _MAT4_H_

#include "math.h"

namespace Core { namespace Math {
	struct Mat4
	{
	 	union {
			float elements[4 * 4];
	 		Vec4 columns[4];
 		};

	 	Mat4();
	 	Mat4(float diagonal);

	 	static Mat4 identity();
	 	
	 	static Mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
	 	static Mat4 perspective(float fov, float aspectRatio, float near, float far);

	 	static Mat4 translation(const Vec3& translation);
	 	static Mat4 rotation(float angle, const Vec3& axis);
	 	static Mat4 scale(const Vec3& scale);
	 
	 	Mat4& multiply(const Mat4& other);

	 	friend Mat4 operator*(Mat4 left, const Mat4& right);
	 	Mat4& operator*=(const Mat4& other);
	};
} }

#endif // _MAT4_H_

