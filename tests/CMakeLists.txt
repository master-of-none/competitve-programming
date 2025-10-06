cmake_minimum_required(VERSION 3.24)
cmake_policy(SET CMP0135 NEW)  # Use extraction time for timestamps

include(FetchContent)

# -----------------------
# Fetch Google Test
# -----------------------
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# -----------------------
# Build Halim Google Test harness
# -----------------------
add_executable(halim_tests halim_tests.cpp)
target_link_libraries(halim_tests gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(halim_tests)