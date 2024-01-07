#include "deck.h"

int findNecessaryAttempts(long long *limit, long long *necessaryAttempts) {
    std::vector<int> deck;

    for (long long i = 0; i < *limit; ++i) {
        deck = makeRandomDeck();
        if (deck[50] == deck[51]) {
            *necessaryAttempts += 1;
        }
    }

    return *necessaryAttempts;
}

std::vector<int> makeRandomDeck() {
    std::vector<int> deck;
    deck.reserve(52);   

    for (int i = 1; i <= 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            deck.push_back(i);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen); 

    return deck;
}

void* similaryCardsThreads(void *arg) {
    Args &ar = *(Args*)arg;
    long long *attemptsPtr = ar.attemptsForCounting;
    long long *necessaryAttemptsThreads = ar.necessaryAttempts;

    necessaryAttemptsThreads += findNecessaryAttempts(attemptsPtr, necessaryAttemptsThreads);
}

int similaryCardsDefault(void *arg) {
    Args &ar = *(Args*)arg;
    long long *attemptsPtr = ar.attemptsForCounting;
    long long *necessaryAttemptsThreads = ar.necessaryAttempts;

    return findNecessaryAttempts(attemptsPtr, necessaryAttemptsThreads);
}