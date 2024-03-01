#pragma once

#include <iostream>
#include <cmath>

constexpr int NUM_POINTS = 3000;
const float PI = 3.1415926535;
constexpr int NUM_BUFFER_SIZE = 33;

extern "C" {
    float SinIntegral(float a, float b, float e);
    char* Translation(long x);
}