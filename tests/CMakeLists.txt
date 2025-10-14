cmake_minimum_required(VERSION 3.24)
cmake_policy(SET CMP0135 NEW)  # Use extraction time for timestamps

# tests/CMakeLists.txt
include(FetchContent)

# Fetch GoogleTest only once
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# Prevent GoogleTest from overriding compiler/linker flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(halim_tests halim_tests.cpp)
target_link_libraries(halim_tests PRIVATE GTest::gtest_main)
set_target_properties(halim_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

include(GoogleTest)
gtest_discover_tests(halim_tests)