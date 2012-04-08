cmake_minimum_required (VERSION 2.6)
project (Epic-Quest)

find_package (SFML)

set (CMAKE_CXX_FLAGS "-g -Wall -std=c++0x")
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_subdirectory (src)
