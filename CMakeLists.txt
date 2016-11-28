cmake_minimum_required(VERSION 2.6)
project(lsa)

set(Gl_VERSION_MAJOR 1)
set(Gl_VERSION_MINOR 0)


if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -pedantic -O2 -g -pg")
	set(CMAKE_CXX_FLAGS "-Wall -Wstrict-aliasing -std=c++0x -O2")

	set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -Wsign-compare -g")
endif(UNIX)

if(WIN32)
	# On Visual 2005 and above, this module can set the debug working directory
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
	include(CreateLaunchers)
	include(MSVCMultipleProcessCompile) # /MP

	if(MINGW)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	ELSE(MINGW)
		add_definitions( "/W3 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" ) # suppress pedantic warnings
	endif(MINGW)
endif(WIN32)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

find_package(SDL2_image REQUIRED)

add_subdirectory(external)

include_directories(
  ${CMAKE_SOURCE_DIR}/external/SDL2-2.0.5/include/
  ${CMAKE_SOURCE_DIR}/engine/
  ${CMAKE_SOURCE_DIR}/.
)

set(ALL_LIBS
	engine
	SDL2
	${SDL2IMAGE_LIBRARY}
)

include_directories(
  /external/SDL2-2.0.5/include
  /external/
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR} ${PROJECT_BINARY_DIR})
add_library(engine
	engine/entity.cpp
	engine/entity.h
	engine/image.cpp
	engine/image.h
	engine/renderer.cpp
	engine/renderer.h
	engine/resourcemanager.cpp
	engine/resourcemanager.h
	engine/scene.cpp
	engine/scene.h
	engine/scenemanager.cpp
	engine/scenemanager.h
	engine/input.cpp
	engine/input.h
	engine/vector2.cpp
	engine/vector2.h
)

add_executable(lsa
	lsa/entities
	lsa/entities/planet.cpp
	lsa/entities/planet.h
	lsa/entities/spaceship.cpp
	lsa/entities/spaceship.h
	lsa/entities/bullet.cpp
	lsa/entities/bullet.h
	lsa/core.cpp
	lsa/particle.cpp
	lsa/particle.h
	lsa/particlesystem.cpp
	lsa/particlesystem.h
	lsa/scenes/mainspace.cpp
	lsa/scenes/mainspace.h
)


target_link_libraries(lsa ${ALL_LIBS})

file(
	COPY assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
