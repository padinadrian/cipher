# Top-level CMake file
cmake_minimum_required(VERSION 3.5)
project(cipher)

# Version information
set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 2)
set(${PROJECT_NAME}_VERSION_BUGFIX 1)

# Universal settings
include_directories("${CMAKE_SOURCE_DIR}/include")

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Individual projects
add_subdirectory("source")
add_subdirectory("tests")

