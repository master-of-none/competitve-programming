# tests/CMakeLists.txt

cmake_minimum_required(VERSION 3.24)  # Required for CMP0135
cmake_policy(SET CMP0135 NEW)  # Use extraction time for timestamps

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE  # Explicitly set to use extraction time
)

# Prevent GoogleTest from adding its own main()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
