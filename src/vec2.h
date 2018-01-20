/*
 * vec2.h
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
	struct Vec2 {
		float x,y;

	 	Vec2();
	 	Vec2(const float& x, const float& y);

	 	Vec2& add(const Vec2& other);
	 	Vec2& subtract(const Vec2& other);
	 	Vec2& multiply(const Vec2& other);
	 	Vec2& divide(const Vec2& other);

		friend Vec2 operator+(Vec2 left, const Vec2& right);
	 	friend Vec2 operator-(Vec2 left, const Vec2& right);
	 	friend Vec2 operator*(Vec2 left, const Vec2& right);
	 	friend Vec2 operator/(Vec2 left, const Vec2& right);

	 	Vec2& operator+=(const Vec2& other);
	 	Vec2& operator-=(const Vec2& other);
	 	Vec2& operator*=(const Vec2& other);
	 	Vec2& operator/=(const Vec2& other);

	 	bool operator==(const Vec2& other);
	 	bool operator!=(const Vec2& other);
	 
	 	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);
	};
} }