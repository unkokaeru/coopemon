cmake_minimum_required(VERSION 3.10)
project(Coopemon)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
    include
    source
    source/characters
    source/config
    source/gameplay
    source/interface
    source/utilities
)

# Source files
file(GLOB_RECURSE SOURCES
    "source/*.cpp"
)

# Create the executable
add_executable(coopemon ${SOURCES})