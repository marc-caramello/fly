set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.10)
project(Fly)

set(CMAKE_GENERATOR "Unix Makefiles")
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

# Set the CMP0074 policy to NEW
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

# Add directory containing FindSFML.cmake to module path
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/;${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}")

# Add sources
file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/Debug/*.cpp"
    "${PROJECT_SOURCE_DIR}/extlibs/src/*.cpp"
)

# Copy shaders and resources
file(COPY shaders DESTINATION .)
file(COPY resources DESTINATION .)

include_directories(
    "${PROJECT_SOURCE_DIR}/include" 
    "${PROJECT_SOURCE_DIR}/extlibs" 
    "${PROJECT_SOURCE_DIR}/lib" 
    "C:/msys64"
)

add_executable(Fly ${SOURCES})

set_property(TARGET Fly PROPERTY CXX_STANDARD 17)
set_property(TARGET Fly PROPERTY CXX_STANDARD_REQUIRED ON)