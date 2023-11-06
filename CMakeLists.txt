cmake_minimum_required(VERSION 3.25)
project(Fly)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/Debug/*.cpp"
    "${PROJECT_SOURCE_DIR}/extlibs/src/*.cpp"
)
find_package(SFML REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(Fly ${SOURCES})
set_property(TARGET Fly PROPERTY CXX_STANDARD 17)
set_property(TARGET Fly PROPERTY CXX_STANDARD_REQUIRED ON)