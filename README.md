# competitve-programming

This repository contains my solutions to various competitive programming problems using **C++17**, organized and built with **CMake**.

## Dependencies

-   cmake
-   gtest

## ⚙️ Build Instructions

1. Create and navigate to the `build/` directory:

    ```bash
    mkdir build && cd build
    ```

2. Generate Makefiles using CMake:

    ```bash
    cmake ..
    ```

3. Build all problem executables:

    ```bash
    make
    ```

4. Run a solution:

    ```bash
    ./bin/<problemName>
    ```

5. To run UVA problems, use:
    ```bash
    ./bin/<problemName> < ../problems/uva/<chapter>/input.txt
    ```
