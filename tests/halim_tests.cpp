#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

// ======================================================
// 🔹 Helper: Run a program and capture its output
// ======================================================
std::string run_program(const std::string& exe_path,
                        const std::string& input_file) {
    std::string temp_output = "temp_output.txt";
    std::string cmd = exe_path + " < " + input_file + " > " + temp_output;

    std::cout << "\n[ RUN ] Command: " << cmd << std::endl;

    int ret = std::system(cmd.c_str());
    if (ret != 0) {
        std::cerr << "[ ERROR ] Execution failed for " << exe_path << std::endl;
        throw std::runtime_error("Execution failed for " + exe_path);
    }

    std::ifstream out(temp_output);
    if (!out.is_open()) {
        throw std::runtime_error("Could not open output file: " + temp_output);
    }

    std::stringstream buffer;
    buffer << out.rdbuf();
    std::string output = buffer.str();
    return output;
}

// ======================================================
// 🔹 Helper: Compare output with expected output
// ======================================================
void check_output(const std::string& exe_path, const std::string& input_file,
                  const std::string& output_file) {
    std::string output = run_program(exe_path, input_file);

    std::ifstream expected_file(output_file);
    if (!expected_file.is_open()) {
        throw std::runtime_error("Could not open expected output file: " +
                                 output_file);
    }

    std::stringstream expected_buffer;
    expected_buffer << expected_file.rdbuf();
    std::string expected_output = expected_buffer.str();

    // Trim trailing newline
    auto trim_end = [](std::string& s) {
        while (!s.empty() && (s.back() == '\n' || s.back() == '\r'))
            s.pop_back();
    };
    trim_end(output);
    trim_end(expected_output);

    EXPECT_EQ(output, expected_output);
}

// ======================================================
// 🔹 Parameterized GTest Setup
// ======================================================
class DynamicTest : public ::testing::TestWithParam<
                        std::tuple<std::string, std::string, std::string>> {};

TEST_P(DynamicTest, Run) {
    auto [exe_path, input_file, output_file] = GetParam();
    check_output(exe_path, input_file, output_file);
}

// ======================================================
// 🔹 Dynamic Test Collector
// ======================================================
std::vector<std::tuple<std::string, std::string, std::string>> collect_tests() {
    std::vector<std::tuple<std::string, std::string, std::string>> tests;

    //! Path to Halim (change when needed)
    std::string halim_folder =
        "/Volumes/Personal/Programming/competitve-programming/halim/";

    for (const auto& chapter : fs::directory_iterator(halim_folder)) {
        if (!chapter.is_directory()) continue;

        for (const auto& problem : fs::directory_iterator(chapter.path())) {
            if (problem.path().extension() != ".cpp") continue;

            std::string name = problem.path().stem().string();
            std::string exe = "../bin/halim/" + name;
            std::string in =
                chapter.path().string() + "/tests/" + name + "_input.txt";
            std::string out =
                chapter.path().string() + "/tests/" + name + "_output.txt";

            if (fs::exists(exe) && fs::exists(in) && fs::exists(out))
                tests.emplace_back(exe, in, out);
        }
    }
    return tests;
}

// ======================================================
// 🔹 Instantiate Tests Dynamically
// ======================================================
INSTANTIATE_TEST_SUITE_P(
    HalimProblems, DynamicTest, ::testing::ValuesIn(collect_tests()),
    [](const ::testing::TestParamInfo<
        std::tuple<std::string, std::string, std::string>>& info) {
        return fs::path(std::get<0>(info.param)).stem().string();  // test name
    });