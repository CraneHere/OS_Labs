#include <pthread.h>
#include <iostream>
#include "monteCheckDefault.h"
#include "monteCheckThreads.h"

int main(int argc, char **argv)
{
    if (argc <= 1) {
        std::cout << "Not enough arguments" << std::endl;
        return -1;
    }

    //checking the program works with similar numbers

    CheckForThreads check1(4);
    CheckForDefault check2;

    double finalChanceForThreads = check1.monteCheck(atoll(argv[1]));
    double finalChanceForDefault = check2.monteCheck(atoll(argv[1]));

    double finalChanceForThreads2 = check1.monteCheck(atoll(argv[1]));
    double finalChanceForDefault2 = check2.monteCheck(atoll(argv[1]));

    std::cout << finalChanceForThreads << std::endl;
    std::cout << finalChanceForDefault << std::endl;
    std::cout << finalChanceForThreads2 << std::endl;
    std::cout << finalChanceForDefault2 << std::endl;
}