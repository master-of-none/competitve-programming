# Competitive Programming

This repository contains my **C++17** solutions to various **competitive programming** problems from platforms and books such as:

-   🧮 [Codeforces](https://codeforces.com/)
-   📘 _Competitive Programming 4_ by Steven & Felix Halim
-   📗 _Competitive Programmer’s Handbook_ by Antti Laaksonen
-   📙 [UVa Online Judge](https://onlinejudge.org/)
-   🧠 Data Structures & Algorithms (DSA) practice problems

All solutions are organized in a **modular CMake project** with a clean build system, consistent formatting, and optional testing setup using **GoogleTest**.

---

## Repository Structure

```
.
├── codeforces/800/       # Codeforces problems (difficulty 800+)
├── cp_handbook/          # Problems from CP Handbook
├── dsa/                  # Data structures and algorithms practice
├── halim/                # Problems from Competitive Programming 3
├── include/              # Shared headers and helper utilities
├── problems/             # Miscellaneous standalone problems
├── tests/                # Unit tests using GoogleTest
├── uva/                  # UVA Online Judge problems
│
├── .clang-format         # Code formatting configuration
├── .clang-tidy           # Static analysis and linting config
├── .gitignore
├── CMakeLists.txt        # CMake build configuration
├── LICENSE               # License file (MIT)
├── README.md             # This file
└── input.txt             # Sample input for testing locally
```

---

## ⚙️ Build & Run Instructions

### 1. Create and navigate to the build directory:

```bash
mkdir build && cd build
```

### 2. Generate build files using CMake:

```bash
cmake ..
```

### 3. Build all problem executables:

```bash
make
```

### 4. Run a specific problem:

Executables are placed in the `bin/` directory after build.

```bash
./bin/<problemName>
```

For example:

```bash
./bin/uva_11581
```

### 5. Run UVA problems with input redirection:

```bash
./bin/<problemName> < ../uva/<chapter>/input.txt
```

Example:

```bash
./bin/uva_11581 < ../uva/chapter1/input.txt
```

### 6. Run tests (if enabled with GoogleTest):

```bash
./bin/tests
```

---

## Dependencies

To build and run this repository, make sure the following tools are installed:

| Dependency                  | Description                 |
| --------------------------- | --------------------------- |
| **CMake ≥ 3.10**            | Build system generator      |
| **g++ / clang++**           | C++17 compatible compiler   |
| **GoogleTest** _(optional)_ | Unit testing framework      |
| **clang-format**            | Code formatting             |
| **clang-tidy**              | Static analysis and linting |

---

## Code Quality and Standards

All code follows **modern C++17 practices** and adheres to consistent formatting and static analysis rules.

-   **clang-format** ensures stylistic consistency
-   **clang-tidy** enforces clean and efficient C++ code
-   **CMake** simplifies modular compilation

You can format or lint code manually using:

```bash
clang-format -i <filename>.cpp
clang-tidy <filename>.cpp
```

---

## Problem Categories

### 📘 Halim (`halim/`)

Problems solved from _Competitive Programming 4_ by Steven and Felix Halim — covering topics like:

-   Ad hoc problems
-   Data structures
-   Dynamic programming
-   Graph algorithms
-   Greedy techniques

### 📗 CP Handbook (`cp_handbook/`)

Problems based on _Competitive Programmer’s Handbook_ by Antti Laaksonen — organized by:

-   Sorting and searching
-   Graph theory
-   Mathematics and number theory
-   Range queries and trees

### 🧮 Codeforces (`codeforces/800/`)

Problems from Codeforces categorized by difficulty (starting from 800+).  
Each file follows a simple input/output style with testable examples.

### 🧠 DSA (`dsa/`)

Practice problems for mastering:

-   Arrays, linked lists, stacks, queues
-   Trees, heaps, and graphs
-   Sorting, searching, and recursion patterns

### 📙 UVA (`uva/`)

Solutions to classical UVa problems, e.g.:

-   100 - The 3n + 1 Problem
-   272 - TEX Quotes
-   11581 - Grid Successors

Run using redirected input:

```bash
./bin/uva_11581 < ../uva/chapter1/input.txt
```

---

## Testing

If **GoogleTest** is integrated, the repository supports automated unit testing.

Build and run tests:

```bash
cmake -DBUILD_TESTS=ON ..
make
./bin/tests
```

---

## Example Workflow

```bash
# Clone the repository
git clone https://github.com/<username>/competitive-programming.git
cd competitive-programming

# Configure and build
mkdir build && cd build
cmake ..
make

# Run a specific problem
./bin/codeforces_800_ArrivalOfTheGeneral

# Run with redirected input
./bin/uva_11581 < ../uva/chapter1/input.txt
```

---

## License

This project is licensed under the **MIT License** — see [LICENSE](LICENSE) for details.

---

## Acknowledgements

-   [Steven & Felix Halim — _Competitive Programming 4_](https://cpbook.net/)
-   [Antti Laaksonen — _Competitive Programmer’s Handbook_](https://cses.fi/book/index.html)
-   [Codeforces](https://codeforces.com/)
-   [UVa Online Judge](https://onlinejudge.org/)
-   [GoogleTest](https://github.com/google/googletest)

---

## Future Plans

-   Add CMake targets for **individual difficulty folders**
-   Integrate **automated testing** for UVA input/output
-   Add **LeetCode** and **AtCoder** sections
-   Set up **GitHub Actions** for CI with `clang-tidy` checks

---

> “Practice like you’ve never won.  
> Compete like you’ve never lost.”
