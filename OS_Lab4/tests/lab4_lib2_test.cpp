#include <gtest/gtest.h>

#include <cstring>
#include <utility>

#include "lib.h"

TEST(fourthLabTest, SinIntegralStaticTest1) {
    float result = SinIntegral(0, PI, 0.01);
    EXPECT_FLOAT_EQ(result, 2);
}

TEST(fourthLabTest, SinIntegralStaticTest2) {
    float result = SinIntegral(0, PI/2, 0.01);
    EXPECT_FLOAT_EQ(result, 0.9999997);
}

TEST(fourthLabTest, SinIntegralStaticTest3) {
    float result = SinIntegral(0, PI/3, 0.01);
    EXPECT_FLOAT_EQ(result, 0.49999979);
}

TEST(FourthLabTests, TranslationTest) {
    auto deleter = [](char *str) { std::free(str); };
    std::unique_ptr<char, decltype(deleter)> str(Translation(0), deleter);
    EXPECT_TRUE(std::strcmp(str.get(), "0") == 0);
    str.reset(Translation(5));
    EXPECT_TRUE(std::strcmp(str.get(), "12") == 0);
    str.reset(Translation(888));
    EXPECT_TRUE(std::strcmp(str.get(), "1012220") == 0);
    str.reset(Translation(-1));
    EXPECT_EQ(str.get(), nullptr);
}