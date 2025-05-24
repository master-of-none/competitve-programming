cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

include_directories(include)

file(GLOB_RECURSE SOURCES "problems/*.cpp")

foreach(SRC ${SOURCES})
    get_filename_component(EXEC_NAME ${SRC} NAME_WE)
    add_executable(${EXEC_NAME} ${SRC})
endforeach()
