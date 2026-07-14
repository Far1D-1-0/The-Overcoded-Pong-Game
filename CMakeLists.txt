cmake_minimum_required(VERSION 4.1)

project(Pong)

set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 3.1 COMPONENTS Graphics System Network Audio Window REQUIRED)

set(PONG_LIBS_HEADER_BASE_DIRS
	${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(src)

