#include "lib.h"
#include "utils.h"

float SinIntegral(float a, float b, float e) {
    float integral = 0.0;
    e = (b - a) / NUM_POINTS;
    for (int i = 0; i <= NUM_POINTS; ++i) {
        integral = integral + e * sin(a + e * (i - 0.5));
    }
    return integral;
}

char* Translation(long x) {
    if (x < 0) {
        return nullptr;
    }
    char* binary = (char*)malloc(NUM_BUFFER_SIZE);
    if (!binary) {
        return binary;
    }
    int i = 0;
    do {
        binary[i++] = '0' + (x & 1);
        x >>= 1;
    } while(x);
    binary[i] = '\0';
    ReverseString(binary, i);
    return binary;
}