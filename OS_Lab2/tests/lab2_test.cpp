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

    double finalChanceForThreads = check1.monteCheck(12000, 4);
    double finalChanceForDefault = check2.monteCheck(12000, 1);

    double difference = abs(finalChanceForDefault - finalChanceForThreads);

    ASSERT_TRUE(difference < 200);
}

TEST(test2, equalTest) {
    CheckForThreads check3;
    CheckForDefault check4;

    double finalChanceForThreads = check3.monteCheck(12000, 4);
    double finalChanceForDefault = check4.monteCheck(12000, 1);

    double difference = abs(finalChanceForDefault - finalChanceForThreads);

    ASSERT_TRUE(difference < 200);
}

TEST(test3, equalTest) {
    CheckForThreads check3;
    CheckForDefault check4;

    double finalChanceForThreads = check3.monteCheck(43499, 3);
    double finalChanceForDefault = check4.monteCheck(43499, 1);

    double difference = abs(finalChanceForDefault - finalChanceForThreads);

    ASSERT_TRUE(difference < 200);
}