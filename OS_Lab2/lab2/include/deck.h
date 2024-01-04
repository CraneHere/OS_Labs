#pragma once

#include <pthread.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

class Check {
public:
    virtual double monteCheck(long long allAttempts, int numThreads) = 0;
};

std::vector<int> makeRandomDeck();
int similaryCardsDefault(long long allAttempts);
void* similaryCardsThreads(void *arg);
int findNecessaryAttempts(long long limit, long long necessaryAttempts);
int printAttemptsForThreats();