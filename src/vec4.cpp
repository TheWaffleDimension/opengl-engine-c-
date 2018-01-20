// vec4.cpp
//
// Copyright (C) 2018 - Mason Harris
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include <vec4.h>

namespace Core { namespace Math {
	Vec4::Vec4(const float& x, const float& y, const float& z, const float& w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vec4& Vec4::add(const Vec4& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Vec4& Vec4::subtract(const Vec4& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	Vec4& Vec4::multiply(const Vec4& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	Vec4& Vec4::divide(const Vec4& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}

	Vec4 operator+(Vec4 left, const Vec4& right) {
		return left.add(right);
	}

	Vec4 operator-(Vec4 left, const Vec4& right) {
		return left.subtract(right);
	}

	Vec4 operator*(Vec4 left, const Vec4& right) {
		return left.multiply(right);
	}

	Vec4 operator/(Vec4 left, const Vec4& right) {
		return left.divide(right);
	}

	Vec4& Vec4::operator+=(const Vec4& other) {
		return add(other);
	}

	Vec4& Vec4::operator-=(const Vec4& other) {
		return subtract(other);
	}

	Vec4& Vec4::operator*=(const Vec4& other) {
		return multiply(other);
	}

	Vec4& Vec4::operator/=(const Vec4& other) {
		return divide(other);
	}

	bool Vec4::operator==(const Vec4& other) {
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool Vec4::operator!=(const Vec4& other) {
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec4& vector) {
		stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}
} }