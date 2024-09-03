cmake_minimum_required(VERSION 3.10)

project(pajk)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


file(GLOB_RECURSE SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp glad/glad.c)

add_executable(pajk ${SOURCE})

target_link_libraries(pajk PUBLIC glfw)