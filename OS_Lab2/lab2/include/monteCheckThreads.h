#pragma once

#include "deck.h"

class CheckForThreads : public Check {
public:

    CheckForThreads(int numThreads) {
        numThreads_ = numThreads;
    }

    double monteCheck(long long allAttempts) override;

private:
    int numThreads_;
};