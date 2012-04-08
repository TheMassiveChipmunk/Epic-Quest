include_directories (${CMAKE_TEST_SOURCE_DIR}/src)
include_directories (${CMAKE_TEST_SOURCE_DIR}/include)

link_directories (${CMAKE_TEST_BINARY_DIR}/src)
link_directories (${CMAKE_TEST_BINARY_DIR}/include)

add_executable (Epic-Quest Box.cpp Character.cpp Enemy.cpp Level.cpp Player.cpp 
	              Util.cpp Bullet.cpp Engine.cpp main.cpp Point.cpp)

target_link_libraries (Epic-Quest sfml-audio sfml-graphics sfml-system)
