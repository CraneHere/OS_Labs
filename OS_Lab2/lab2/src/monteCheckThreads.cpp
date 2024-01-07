#include "monteCheckThreads.h"
#include "deck.h"

double CheckForThreads::monteCheck(long long allAttempts) {
    long long attemptsForCounting = allAttempts / numThreads_;
    long long necessaryAttempts = 0;

    pthread_t tid[numThreads_];

    if (allAttempts % numThreads_ == 0) {
        for (int i = 0; i < numThreads_; i++) {
            Args ar = {&necessaryAttempts, &attemptsForCounting};
            pthread_create(&tid[i], nullptr, similaryCardsThreads, &ar);
        }
    } else {
        int remainder = allAttempts % numThreads_;
        long long remainingAttempts = attemptsForCounting + remainder;

        for (int i = 0; i < numThreads_ - 1; i++) {
            Args ar1 = {&necessaryAttempts, &attemptsForCounting};
            pthread_create(&tid[i], nullptr, similaryCardsThreads, &ar1);
        }
        Args ar2 = {&necessaryAttempts, &remainingAttempts};
        pthread_create(&tid[numThreads_ - 1], nullptr, similaryCardsThreads, &ar2);
    }

    for (int i = 0; i < numThreads_; i++) {
        pthread_join(tid[i], nullptr);
    }

    return necessaryAttempts;
}