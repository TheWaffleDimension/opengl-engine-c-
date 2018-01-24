/*
 * fileutils.h
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

#include <string>
#include <streambuf>
#include <sstream>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>

namespace Core { namespace Utils {
	class FileUtils {
	 public:
		static std::string read_file(const char* filepath) {
			std::string fp = filepath;
			/*
			std::ifstream infile { fp };
			std::string file_contents { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
			return file_contents;
		 	*/
			std::ifstream t(fp);
			std::stringstream buffer;
			buffer << t.rdbuf();
			std::string fileContents = buffer.str();
			std::cout << fileContents << std::endl;
			return fileContents;
		}
 	};
} }