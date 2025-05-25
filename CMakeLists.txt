cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

include_directories(include)
enable_testing()
add_subdirectory(tests)

file(GLOB_RECURSE SOURCES "problems/*.cpp")

foreach(SRC ${SOURCES})
    get_filename_component(EXEC_NAME ${SRC} NAME_WE)
    add_executable(${EXEC_NAME} ${SRC})
    set_target_properties(${EXEC_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    target_link_libraries(${EXEC_NAME} gtest gtest_main)
    include(GoogleTest)
    gtest_discover_tests(${EXEC_NAME})
endforeach()
