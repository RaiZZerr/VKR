
# ѕроверка версии CMake
cmake_minimum_required(VERSION 3.5)

# Ќазвание проекта и проверка доступности компил€тор€ с++
project(API)

# —оздание библиотек, от которых зависит динамическа€ библиотека
add_library(random randomization.h randomization.cpp)
add_library(writeinfile writefile.h writefile.cpp)
add_library(shapes figures.h figures.cpp)

# —оздание динамической библиотеки с именем API
add_library(API SHARED api.cpp)
add_library(Static_lib api.cpp)
add_executable(myAPI main.cpp)

target_link_libraries(shapes
	PRIVATE
		random
)

target_link_libraries(shapes
	PRIVATE
		random
)

target_link_libraries(API
	PRIVATE
		shapes
		writeinfile
)

target_link_libraries(Static_lib
	PRIVATE
		shapes
		writeinfile
)

target_link_libraries(myAPI
	PUBLIC
		Static_lib
)