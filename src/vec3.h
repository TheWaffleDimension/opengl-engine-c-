/*
 * vec3.h
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
	struct Vec3 {
		float x,y,z;

	 	Vec3();
	 	Vec3(const float& x, const float& y, const float& z);

	 	Vec3& add(const Vec3& other);
	 	Vec3& subtract(const Vec3& other);
	 	Vec3& multiply(const Vec3& other);
	 	Vec3& divide(const Vec3& other);

		friend Vec3 operator+(Vec3 left, const Vec3& right);
	 	friend Vec3 operator-(Vec3 left, const Vec3& right);
	 	friend Vec3 operator*(Vec3 left, const Vec3& right);
	 	friend Vec3 operator/(Vec3 left, const Vec3& right);

	 	Vec3& operator+=(const Vec3& other);
	 	Vec3& operator-=(const Vec3& other);
	 	Vec3& operator*=(const Vec3& other);
	 	Vec3& operator/=(const Vec3& other);

	 	bool operator==(const Vec3& other);
	 	bool operator!=(const Vec3& other);
	 
	 	friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);
	};
} }