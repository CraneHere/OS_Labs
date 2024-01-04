#pragma once

#include "deck.h"

class CheckForDefault : public Check{
public:
    double monteCheck(long long allAttempts, int numThreads) override;  
};