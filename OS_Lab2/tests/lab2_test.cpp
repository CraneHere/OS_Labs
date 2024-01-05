#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <memory>
#include <stdlib.h>

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