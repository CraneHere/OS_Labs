#include "monteCheckDefault.h"
#include "deck.h"

double CheckForDefault::monteCheck(long long allAttempts) {
    long long necessaryAttempts = 0;
    Args ar = {&necessaryAttempts, &allAttempts};
    return similaryCardsDefault(&ar);
}