#include "monteCheckThreads.h"
#include "deck.h"

double CheckForThreads::monteCheck(long long allAttempts, int numThreads) {
    long long attemptsForCounting = allAttempts / 4;

    pthread_t tid[numThreads];

    if (allAttempts % 4 == 0) {
        for (int i = 0; i < numThreads; i++) {
            pthread_create(&tid[i], nullptr, similaryCardsThreads, &attemptsForCounting);
        }
    } else {
        int remainder = allAttempts % 4;
        long long remainingAttempts = attemptsForCounting + remainder;

        for (int i = 0; i < numThreads - 1; i++) {
            pthread_create(&tid[i], nullptr, similaryCardsThreads, &attemptsForCounting);
        }
        pthread_create(&tid[numThreads - 1], nullptr, similaryCardsThreads, &remainingAttempts);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(tid[i], nullptr);
    }

    return printAttemptsForThreats();
}