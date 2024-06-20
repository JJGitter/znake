cmake_minimum_required(VERSION 3.17)
project(znake)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(znake src/main.cpp src/snake.cpp)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Link SFML libraries to the executable
target_link_libraries(znake sfml-graphics sfml-window sfml-system)