## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir). \
	$(GLEW_CFLAGS). \
	$(glew_CFLAGS). \
	$(GL_CFLAGS). \
	$(GL_CFLAGS). \
	$(GL_CFLAGS). \
	$(GLFW3_CFLAGS)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = sparky_engine

sparky_engine_SOURCES = \
	main.cc \
	glfw3.h \
	window.cc \
	window.h \
	input.cpp \
	input.h \
	vec2.h \
	vec2.cpp \
	vec3.cpp \
	vec3.h \
	vec4.cpp \
	vec4.h \
	math.h \
	mat4.cpp \
	mat4.h \
	fileutils.h

sparky_engine_LDFLAGS = 

sparky_engine_LDADD =  \
	$(GLFW3_LIBS) \
	$(GL_LIBS) \
	$(glew_LIBS) \
	$(GLEW_LIBS)


