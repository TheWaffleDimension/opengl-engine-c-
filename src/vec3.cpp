// vec3.cpp
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

#include <vec3.h>

namespace Core { namespace Math {
	Vec3::Vec3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vec3::Vec3(const float& x, const float& y, const float& z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3& Vec3::add(const Vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vec3& Vec3::subtract(const Vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vec3& Vec3::multiply(const Vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vec3& Vec3::divide(const Vec3& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vec3 operator+(Vec3 left, const Vec3& right) {
		return left.add(right);
	}

	Vec3 operator-(Vec3 left, const Vec3& right) {
		return left.subtract(right);
	}

	Vec3 operator*(Vec3 left, const Vec3& right) {
		return left.multiply(right);
	}

	Vec3 operator/(Vec3 left, const Vec3& right) {
		return left.divide(right);
	}

	Vec3& Vec3::operator+=(const Vec3& other) {
		return add(other);
	}

	Vec3& Vec3::operator-=(const Vec3& other) {
		return subtract(other);
	}

	Vec3& Vec3::operator*=(const Vec3& other) {
		return multiply(other);
	}

	Vec3& Vec3::operator/=(const Vec3& other) {
		return divide(other);
	}

	bool Vec3::operator==(const Vec3& other) {
		return x == other.x && y == other.y && z == other.z;
	}

	bool Vec3::operator!=(const Vec3& other) {
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec3& vector) {
		stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
} }