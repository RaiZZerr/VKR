
cmake_minimum_required(VERSION 3.5)

project(API)

set(SOURCES
		main.cpp
		figures.cpp
		writefile.cpp
		randomization.cpp
		api.cpp
)

set(HEADERS
		figures.h
		writefile.h
		randomization.h
		api.h
)

add_executable(API ${SOURCES} ${HEADERS})
set_target_properties(
	API PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)