cmake_minimum_required(VERSION 3.25)
project(Fly)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Debug/*.cpp
    ${PROJECT_SOURCE_DIR}/extlibs/src/*.cpp
)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/extlibs
)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(SFML REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

add_executable(Fly ${SOURCES})
set_property(TARGET Fly PROPERTY CXX_STANDARD 17)
set_property(TARGET Fly PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(Fly PRIVATE GLEW::GLEW)
target_link_libraries(Fly PRIVATE sfml-window sfml-graphics sfml-system)

add_custom_command(TARGET Fly POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Fly.exe ${PROJECT_SOURCE_DIR}/Fly.exe
    COMMAND taskkill /F /IM ninja.exe
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
)