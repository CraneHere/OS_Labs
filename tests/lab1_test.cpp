#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <memory>

#include "parent.hpp"

namespace fs = std::__fs::filesystem;

using TStringVector = std::vector<std::string>;

const std::string fileWithInput = "i.txt";
const std::string fileWithOutput1 = "o1.txt";
const std::string fileWithOutput2 = "o2.txt";

TEST(Lab1, SimpleTest) {
    std::array<std::string, 5> input = {
        "abc",
        "bebe",
        "meow",
        "lo lo",
        ""
    };

    std::array<std::string, 2> expOutput1 = {
        "abc",
        "lo lo"
    };

    std::array<std::string, 3> expOutput2 = {
        "bebe",
        "meow",
        ""
    };

    {
        auto inFile = std::ofstream(fileWithInput);

        inFile << fileWithOutput1 << '\n';
        inFile << fileWithOutput2 << '\n';

        for(const auto& line : input) {
            inFile << line << '\n';
        }
    }

    std::ifstream inFile(fileWithInput);

    if (getenv("PATH_TO_CHILD") == NULL) {
        printf("WARNING: PATH_TO_CHILD was not specified.\n");
    }
    ParentRoutine(getenv("PATH_TO_CHILD"), inFile);

    auto outFile1 = std::ifstream(fileWithOutput1);
    auto outFile2 = std::ifstream(fileWithOutput2);

    ASSERT_TRUE(outFile1.good());
    ASSERT_TRUE(outFile2.good());

    std::vector<std::string> output1;
    std::vector<std::string> output2;
    for (std::string line; std::getline(outFile1, line); ) {
        output1.push_back(line);
    }
    for (std::string line; std::getline(outFile2, line); ) {
        output2.push_back(line);
    }

    ASSERT_TRUE(output1.size() == expOutput1.size());
    for (size_t i = 0; i < output1.size(); i++) {
        EXPECT_EQ(output1[i], expOutput1[i]);
    }
    ASSERT_TRUE(output2.size() == expOutput2.size());
    for (size_t i = 0; i < output2.size(); i++) {
        EXPECT_EQ(output2[i], expOutput2[i]);
    }

    auto removeIfExists = [](const std::string& path) {
        if (fs::exists(path)) {
            fs::remove(path);
        }
    };

    removeIfExists(fileWithInput);
    removeIfExists(fileWithOutput1);
    removeIfExists(fileWithOutput2);
}
