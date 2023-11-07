cmake_minimum_required(VERSION 3.25)
project(Fly)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Debug/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Log.cpp  # Add this line
)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/Debug
    ${PROJECT_SOURCE_DIR}/include/glm
    ${PROJECT_SOURCE_DIR}/include/glm/detail
    ${PROJECT_SOURCE_DIR}/include/glm/ext
    ${PROJECT_SOURCE_DIR}/include/glm/gtc
    ${PROJECT_SOURCE_DIR}/include/glm/gtx
    ${PROJECT_SOURCE_DIR}/include/glm/simd
)
find_package(GLEW REQUIRED)
find_package(SFML REQUIRED)

add_executable(Fly ${SOURCES})  # Modify this line
set_property(TARGET Fly PROPERTY CXX_STANDARD 17)
set_property(TARGET Fly PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(Fly PRIVATE GLEW::GLEW)
target_link_libraries(Fly PRIVATE sfml-window sfml-graphics sfml-system)