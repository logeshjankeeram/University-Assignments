# this is the cmake file for our  game
# had to use version 3.10 cuz thats what works on my laptop
cmake_minimum_required(VERSION 3.10)
project(MazeRunner)

# using c++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# all our cpp files
set(SOURCES
    Source/main.cpp
    Source/Game.cpp
    Source/Player.cpp
    Source/Trap.cpp
    Source/LevelManager.cpp
    Source/Utils.cpp
)

# all our header files
set(HEADERS
    Source/Game.hpp
    Source/Player.hpp
    Source/Trap.hpp
    Source/LevelManager.hpp
)

# make the game executable
add_executable(MazeRunner ${SOURCES} ${HEADERS})


target_link_libraries(MazeRunner PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# copy game resources to build folder
file(COPY Source/Resources DESTINATION ${CMAKE_BINARY_DIR})

# copy sound files - had to add this after sound wasnt working
file(COPY ${CMAKE_SOURCE_DIR}/Resources/Sounds DESTINATION ${CMAKE_BINARY_DIR}/Resources)

# copy font file - needed for text
configure_file(${CMAKE_SOURCE_DIR}/arial.ttf ${CMAKE_BINARY_DIR}/arial.ttf COPYONLY) 