#include "lib.hpp"
#include "utils.hpp"
#include <vector>

extern "C" float SinIntegral(float a, float b, float e) {
    float integral = 0.0;
    e = (b - a) / NUM_POINTS;
    for (int i = 1; i < NUM_POINTS; ++i) {
        float x1 = a + i * e;
        float x2 = a + (i + 1) * e;
        integral += 0.5 * e * (sin(x1) + sin(x2));
    }
    return integral;
}

extern "C" char* Translation(long x) {
    if (x < 0) {
        return nullptr;
    }
    char* trinary = (char*)malloc(NUM_BUFFER_SIZE);
    if (!trinary) {
        return trinary;
    }
    int i = 0;
    do {
        trinary[i++] = '0' + (x % 3);
        x /= 3;
    } while (x);
    trinary[i] = '\0';
    ReverseString(trinary, i);
    return trinary;
}