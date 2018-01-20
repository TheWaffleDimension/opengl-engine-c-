/*
 * vec4.h
 *
 * Copyright (C) 2018 - Mason Harris
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

namespace Core { namespace Math {
	struct Vec4 {
		float x,y,z,w;
	 	
	 	Vec4() = default;
	 	Vec4(const float& x, const float& y, const float& z, const float& w);

	 	Vec4& add(const Vec4& other);
	 	Vec4& subtract(const Vec4& other);
	 	Vec4& multiply(const Vec4& other);
	 	Vec4& divide(const Vec4& other);

		friend Vec4 operator+(Vec4 left, const Vec4& right);
	 	friend Vec4 operator-(Vec4 left, const Vec4& right);
	 	friend Vec4 operator*(Vec4 left, const Vec4& right);
	 	friend Vec4 operator/(Vec4 left, const Vec4& right);

	 	Vec4& operator+=(const Vec4& other);
	 	Vec4& operator-=(const Vec4& other);
	 	Vec4& operator*=(const Vec4& other);
	 	Vec4& operator/=(const Vec4& other);

	 	bool operator==(const Vec4& other);
	 	bool operator!=(const Vec4& other);
	 
	 	friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);
	};
} }