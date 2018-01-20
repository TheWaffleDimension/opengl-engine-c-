/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * mat4.cpp
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

#include "mat4.h"

namespace Core { namespace Math {
	Mat4::Mat4() {
		for (int i=0; i < (4*4); i++) {
			elements[i] = 0;
		}
	}

	Mat4::Mat4(float diagonal) {
		for (int i=0; i < (4*4); i++) {
			elements[i] = 0;
		}

		elements[0+0 * 4] = 1.0f;
		elements[1+1 * 4] = 1.0f;
		elements[2+2 * 4] = 1.0f;
		elements[3+3 * 4] = 1.0f;
	}

	Mat4 Mat4::identity() {
		return Mat4(1.0f);
	}

	Mat4 Mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
		Mat4 result(0.0f);

		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near - far);

		result.elements[3 + 3 * 4] = 1.0f;

		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);

		return result;
	}
	
	Mat4 Mat4::perspective(float fov, float aspectRatio, float near, float far) {
		Mat4 result(0.0f);

		float q = tan(toRadians(0.5f * fov));
		float a = q * aspectRatio;

		
		result.elements[0 + 0 * 4] = 1.0f / a;
		result.elements[1 + 1 * 4] = 1.0f / q;
		result.elements[2 + 2 * 4] = -1.0f * ((far + near) / (far - near));

		result.elements[2 + 3 * 4] = -1.0f * ((2.0f * far * near) / (far - near));
		
		result.elements[3 + 2 * 4] = -1.0f;

		return result;
	}

	Mat4 Mat4::translation(const Vec3& translation) {
		Mat4 result(1.0f);

		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;

		return result;
	}
	
 	Mat4 Mat4::rotation(float angle, const Vec3& axis) {
		Mat4 result(1.0f);

		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elements[0 + 0 * 4] = x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = x * z * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + x * s;

		result.elements[0 + 2 * 4] = x * z * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * omc + c;

		return result;
	}
	
 	Mat4 Mat4::scale(const Vec3& scale) {
		Mat4 result(1.0f);

		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
	}

	Mat4& Mat4::multiply(const Mat4& other) {
		Mat4 result(1.0f);

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				float sum = 0.0f;
				for (int e = 0; e < 4; e++) {
					sum += elements[x + e * 4] * other.elements[e + y * 4];
				}
				result.elements[x + y * 4] = sum;
			}
		}

		return result;
	}

	Mat4 operator*(Mat4 left, const Mat4& right) {
		return left.multiply(right);
	}
	
	Mat4& Mat4::operator*=(const Mat4& other) {
		return multiply(other);
	}
} }