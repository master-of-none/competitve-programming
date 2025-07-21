cmake_minimum_required(VERSION 3.10)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

include_directories(include)
enable_testing()
add_subdirectory(tests)

# Collect sources from all folders
file(GLOB_RECURSE PROBLEM_SOURCES "problems/*.cpp")
file(GLOB_RECURSE UVA_SOURCES "uva/*.cpp")
file(GLOB_RECURSE CF_SOURCES "codeforces/*.cpp")

# Combine into a single list
list(APPEND ALL_SOURCES ${PROBLEM_SOURCES} ${UVA_SOURCES} ${CF_SOURCES})

# Build an executable for each source file
foreach(SRC ${ALL_SOURCES})
    get_filename_component(EXEC_NAME ${SRC} NAME_WE)
    add_executable(${EXEC_NAME} ${SRC})
    set_target_properties(${EXEC_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

    # Only link tests for 'problems/' folder (i.e., exclude 'uva/' and 'codeforces/')
    string(FIND "${SRC}" "/uva/" UVA_FOUND)
    string(FIND "${SRC}" "/codeforces/" CF_FOUND)

    if(UVA_FOUND EQUAL -1 AND CF_FOUND EQUAL -1)
        target_link_libraries(${EXEC_NAME} gtest gtest_main)
        include(GoogleTest)
        gtest_discover_tests(${EXEC_NAME})
    endif()
endforeach()