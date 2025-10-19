cmake_minimum_required(VERSION 3.24)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O0 -g")

include_directories(include)

# Enable CTest for `ctest` command
enable_testing()

# -----------------------
# Add tests subdirectory (fetches Google Test and builds harness)
# -----------------------
add_subdirectory(tests)

# -----------------------
# Collect UVA, Codeforces, Halim sources
# -----------------------
file(GLOB_RECURSE UVA_SOURCES "uva/*.cpp")
file(GLOB_RECURSE CF_SOURCES "codeforces/*.cpp")
file(GLOB_RECURSE HALIM_PROBLEMS "halim/*/*.cpp")  # all problems in all chapters

# -----------------------
# Build UVA and Codeforces executables
# -----------------------
list(APPEND ALL_SOURCES ${UVA_SOURCES} ${CF_SOURCES})
foreach(SRC ${ALL_SOURCES})
    get_filename_component(EXEC_NAME ${SRC} NAME_WE)
    add_executable(${EXEC_NAME} ${SRC})
    set_target_properties(${EXEC_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endforeach()

# -----------------------
# Build Halim problem executables
# -----------------------
foreach(SRC ${HALIM_PROBLEMS})
    get_filename_component(PROG_NAME ${SRC} NAME_WE)
    add_executable(${PROG_NAME} ${SRC})
    set_target_properties(${PROG_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/halim)
endforeach()

# -----------------------
# Register the Google Test binary with CTest
# -----------------------
add_test(NAME HalimTests COMMAND halim_tests)
