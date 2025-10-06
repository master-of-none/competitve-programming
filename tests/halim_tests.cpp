#include <gtest/gtest.h>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

// Run a program with input and capture output
std::string run_program(const std::string& exe_path,
                        const std::string& input_file) {
    std::string temp_output = "temp_output.txt";
    std::string cmd = exe_path + " < " + input_file + " > " + temp_output;
    int ret = std::system(cmd.c_str());
    if (ret != 0) throw std::runtime_error("Execution failed for " + exe_path);

    std::ifstream out(temp_output);
    std::stringstream buffer;
    buffer << out.rdbuf();
    return buffer.str();
}

// Compare program output with expected output
void check_output(const std::string& exe_path, const std::string& input_file,
                  const std::string& output_file) {
    std::string output = run_program(exe_path, input_file);
    std::ifstream expected_file(output_file);
    std::stringstream expected_buffer;
    expected_buffer << expected_file.rdbuf();
    EXPECT_EQ(output, expected_buffer.str());
}

// Generate tests for problems that have input/output files
TEST(HalimProblems, AllProblems) {
    std::string halim_folder = "../halim";  // adjusted for build/tests/ path
    int tested = 0;

    for (const auto& chapter : fs::directory_iterator(halim_folder)) {
        if (!chapter.is_directory()) continue;

        for (const auto& problem : fs::directory_iterator(chapter.path())) {
            if (problem.path().extension() != ".cpp") continue;

            std::string problem_name = problem.path().stem().string();
            std::string exe_path = "../bin/halim/" + problem_name;
            std::string input_file =
                chapter.path().string() + "/" + problem_name + "_input.txt";
            std::string output_file =
                chapter.path().string() + "/" + problem_name + "_output.txt";

            bool has_input = fs::exists(input_file);
            bool has_output = fs::exists(output_file);
            bool has_exe = fs::exists(exe_path);

            if (!has_exe) {
                std::cout << "[ SKIP ] " << problem_name
                          << " (no executable found)\n";
                continue;
            }

            if (!has_input || !has_output) {
                std::cout << "[ SKIP ] " << problem_name
                          << " (missing input/output files)\n";
                continue;
            }

            SCOPED_TRACE("Problem: " + chapter.path().filename().string() +
                         "/" + problem_name);
            check_output(exe_path, input_file, output_file);
            tested++;
        }
    }

    std::cout << "\nTotal problems tested: " << tested << "\n";
}