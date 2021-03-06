/*
 * math.h
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

#ifndef _CORE_MATH_H_
#define _CORE_MATH_H_

#define _USE_MATH_DEFINES
#include <cmath>

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace Core { namespace Math {
	inline float toRadians(float degrees) {
		return degrees * (M_PI / 180.0f);
	}
} }

#endif // _CORE_MATH_H