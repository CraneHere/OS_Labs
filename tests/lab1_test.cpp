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

void Check(const TStringVector& input,
           TStringVector expectedOutput1,
           TStringVector expectedOutput2,
           std::string fileWithInput,
           std::string fileWithOutput1,
           std::string fileWithOutput2) {
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

    ASSERT_TRUE(output1.size() == expectedOutput1.size());
    for (size_t i = 0; i < output1.size(); i++) {
        EXPECT_EQ(output1[i], expectedOutput1[i]);
    }
    ASSERT_TRUE(output2.size() == expectedOutput2.size());
    for (size_t i = 0; i < output2.size(); i++) {
        EXPECT_EQ(output2[i], expectedOutput2[i]);
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

TEST(Lab1, SimpleTest1) {
    TStringVector input = {
        "abc",
        "bebe",
        "nyaa",
        "lo lo",
        ""
    };

    TStringVector expOutput1 = {
        "bc",
        "l l"
    };

    TStringVector expOutput2 = {
        "bb",
        "ny",
        ""
    };

    Check(input, expOutput1, expOutput2, "input1.txt", "output11.txt", "output12.txt");
}

TEST(Lab2, SimpleTest2) {
    TStringVector input = {
        "kok",
        "aabc",
        "IlOvecOding",
        "AAAAaaaa"
    };

    TStringVector expOutput1 = {
        "kk",
        "lvcdng"
    };

    TStringVector expOutput2 = {
        "bc",
        ""
    };

    Check(input, expOutput1, expOutput2, "input2.txt", "output21.txt", "output22.txt");
}

TEST(Lab3, SimpleTest3) {
    TStringVector input = {
        "",
        "1",
        "12",
        "13a",
        "14AB"
    };

    TStringVector expOutput1 = {
        "1",
        "13"
    };

    TStringVector expOutput2 = {
        "",
        "12",
        "14B"
    };

    Check(input, expOutput1, expOutput2, "input3.txt", "output31.txt", "output32.txt");
}

TEST(Lab4, SimpleTest4) {
    TStringVector input = {

    };

    TStringVector expOutput1 = {

    };

    TStringVector expOutput2 = {
        
    };

    Check(input, expOutput1, expOutput2, "input4.txt", "output41.txt", "output42.txt");
}