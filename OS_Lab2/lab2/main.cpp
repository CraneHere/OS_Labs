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
    
    CheckForThreads check1;
    CheckForDefault check2;
    CheckForThreads check3;
    CheckForDefault check4;

    double finalChanceForThreads = check1.monteCheck(atoll(argv[1]), atoll(argv[2]));
    double finalChanceForDefault = check2.monteCheck(atoll(argv[1]), 1);

    double finalChanceForThreads2 = check3.monteCheck(atoll(argv[1]), atoll(argv[2]));
    double finalChanceForDefault2 = check4.monteCheck(atoll(argv[1]), 1);

    std::cout << finalChanceForThreads << std::endl;
    std::cout << finalChanceForDefault << std::endl;
    std::cout << finalChanceForThreads2 << std::endl;
    std::cout << finalChanceForDefault2 << std::endl;
}