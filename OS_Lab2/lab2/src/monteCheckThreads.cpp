#include "monteCheckThreads.h"
#include "deck.h"

double CheckForThreads::monteCheck(long long allAttempts, int numThreads) {
    long long attemptsForCounting = allAttempts / numThreads;
    long long necessaryAttempts = 0;

    pthread_t tid[numThreads];

    if (allAttempts % numThreads == 0) {
        for (int i = 0; i < numThreads; i++) {
            Args ar = {&necessaryAttempts, &attemptsForCounting};
            pthread_create(&tid[i], nullptr, similaryCardsThreads, &ar);
        }
    } else {
        int remainder = allAttempts % numThreads;
        long long remainingAttempts = attemptsForCounting + remainder;

        for (int i = 0; i < numThreads - 1; i++) {
            Args ar1 = {&necessaryAttempts, &attemptsForCounting};
            pthread_create(&tid[i], nullptr, similaryCardsThreads, &ar1);
        }
        Args ar2 = {&necessaryAttempts, &remainingAttempts};
        pthread_create(&tid[numThreads - 1], nullptr, similaryCardsThreads, &ar2);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(tid[i], nullptr);
    }

    return necessaryAttempts;
}