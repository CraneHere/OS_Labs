#pragma once

#include "deck.h"

class CheckForThreads : public Check {
public:
    double monteCheck(long long allAttempts, int numThreads) override;
};