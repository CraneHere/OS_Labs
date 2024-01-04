#pragma once

#include <pthread.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

struct Args {
    long long *necessaryAttempts;
    long long *attemptsForCounting;
};

class Check {
public:
    virtual double monteCheck(long long allAttempts, int numThreads) = 0;
};

std::vector<int> makeRandomDeck();
int similaryCardsDefault(void *arg);
void* similaryCardsThreads(void *arg);
int findNecessaryAttempts(long long *limit, long long *necessaryAttempts);