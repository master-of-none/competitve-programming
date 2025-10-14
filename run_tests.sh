#!/bin/bash
set -e
cmake -S . -B build
cmake --build build
ctest --output-on-failure --test-dir build