#include "BasePrimes.h"

BasePrimes::BasePrimes(int minValue, int maxValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    maxPrimeSqrt = sqrt(maxValue);
    primesToFilter = new char[maxValue + 1];
    for (int i = 0; i < maxValue; i++) primesToFilter[i] = true;
};

BasePrimes::~BasePrimes() {
    delete[] primesToFilter;
}

void BasePrimes::getPrimesToCheck() {
    for (int d = 2; d <= maxPrimeSqrt; d++) {
        if (!primesToFilter[d]) continue;
        for (int i = maxValue / d; i >= d; i--) {
            if (!primesToFilter[i]) continue;
            primesToFilter[i * d] = false;
        }
    }
}
