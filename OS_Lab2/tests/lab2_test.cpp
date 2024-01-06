#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <memory>
#include <stdlib.h>
#include <ctime>

#include "deck.h"
#include "monteCheckThreads.h"
#include "monteCheckDefault.h"

TEST(test1, equalTest) {
    CheckForThreads check1;
    CheckForDefault check2;

    long long attempts = 12000;

    double finalChanceForThreads = check1.monteCheck(attempts, 4);
    double finalChanceForDefault = check2.monteCheck(attempts, 1);

    double probabilityThreads = finalChanceForThreads / attempts;
    double probabilityDefault = finalChanceForDefault / attempts;
    double difference = abs(probabilityDefault - probabilityThreads);

    ASSERT_TRUE(difference < 1);
}

TEST(test2, equalTest) {
    CheckForThreads check1;
    CheckForDefault check2;

    long long attempts = 24360;

    double finalChanceForThreads = check1.monteCheck(attempts, 4);
    double finalChanceForDefault = check2.monteCheck(attempts, 1);

    double probabilityThreads = finalChanceForThreads / attempts;
    double probabilityDefault = finalChanceForDefault / attempts;
    double difference = abs(probabilityDefault - probabilityThreads);

    ASSERT_TRUE(difference < 1);
}

TEST(test3, equalTest) {
    CheckForThreads check1;
    CheckForDefault check2;

    long long attempts = 43269;

    double finalChanceForThreads = check1.monteCheck(attempts, 4);
    double finalChanceForDefault = check2.monteCheck(attempts, 1);

    double probabilityThreads = finalChanceForThreads / attempts;
    double probabilityDefault = finalChanceForDefault / attempts;
    double difference = abs(probabilityDefault - probabilityThreads);

    ASSERT_TRUE(difference < 1);
}

TEST(test4, equalTest) {
    CheckForThreads check1;
    CheckForDefault check2;

    long long attempts = 100000;

    double finalChanceForThreads = check1.monteCheck(attempts, 4);
    double finalChanceForDefault = check2.monteCheck(attempts, 1);

    double probabilityThreads = finalChanceForThreads / attempts;
    double probabilityDefault = finalChanceForDefault / attempts;
    double difference = abs(probabilityDefault - probabilityThreads);
    
    ASSERT_TRUE(difference < 1);
}

TEST(test5, PerfomanceTest) {
    auto getAvgTime = [](int threadCount) {
        CheckForThreads check;

        long long attempts = 100000;

        constexpr int runsCount = 1;

        double avg = 0;

        for(int i = 0; i < runsCount; ++i) {
            auto begin = std::chrono::high_resolution_clock::now();
            check.monteCheck(attempts, threadCount);
            auto end = std::chrono::high_resolution_clock::now();
            avg += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        }

        return avg / runsCount;
    };

    auto singleThread = getAvgTime(1);
    auto multiThread = getAvgTime(4);

    std::cout << "Avg time for 1 thread: " << singleThread << '\n';
    std::cout << "Avg time for 4 threads: " << multiThread << '\n';

    EXPECT_GE(singleThread, multiThread);
}