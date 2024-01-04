#include "deck.h"

long long necessaryAttemptsThreads = 0;

int findNecessaryAttempts(long long limit, long long necessaryAttempts) {
    std::vector<int> deck;

    for (long long i = 0; i < limit; ++i) {
        deck = makeRandomDeck();
        if (deck[50] == deck[51]) {
            necessaryAttempts += 1;
        }
    }

    return necessaryAttempts;
}

std::vector<int> makeRandomDeck() {

    std::vector<int> deck{1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,
        11,11,11,11,12,12,12,12,13,13,13,13}; // 1 - T, 11 - J, 12 - Q, 13 - K

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen); 

    return deck;
}

void* similaryCardsThreads(void *arg) {
    long long *attemptsPtr = (long long *) arg;
    long long limit = *attemptsPtr;

    necessaryAttemptsThreads += findNecessaryAttempts(limit, necessaryAttemptsThreads);
}

int printAttemptsForThreats() {
    return necessaryAttemptsThreads;
}

int similaryCardsDefault(long long allAttempts) {
    long long necessaryAttemptsDefault = 0;
    return findNecessaryAttempts(allAttempts, necessaryAttemptsDefault);
}