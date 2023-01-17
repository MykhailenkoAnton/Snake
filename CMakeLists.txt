cmake_minimum_required(VERSION 3.13)  # CMake version check
project(snake)                       # Create project "tetris"
set(CMAKE_CXX_STANDARD 11)            # Enable c++14 standard

# Add sources files.
set(SOURCE_FILES
    main.cpp
    Gamesnake.cpp
    game_elements/Field.cpp
    game_elements/Snake.cpp
    game_elements/Fruits.cpp
)

# Add headers files.
set(HEADER_FILES
    Gamesnake.h
    game_elements/Field.h
    game_elements/Snake.h
    game_elements/Fruits.h
)

# Add subdirectory.
set(DIRS
    game_elements
)

# set (CMAKE_CXX_STANDARD_LIBRARIES "-lncurses")

# Add executable target.
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${DIRS})