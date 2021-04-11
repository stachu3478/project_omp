#include "BasePrimes.h"

BasePrimes::BasePrimes(int minValue, int maxValue) {
    maxPrimeSqrt = sqrt(maxValue);
    maxPrimesCount = maxValue - minValue;
    primes = new int[maxPrimesCount];
    primesToFilter = new int[maxPrimesCount];
    newPrimesToFilter = new int[maxPrimesCount];
    for (int i = 0; i < maxPrimesCount; i++) primesToFilter[i] = i + minValue;

};

BasePrimes::~BasePrimes() {
    delete[] primes;
    delete[] primesToFilter;
    delete[] newPrimesToFilter;
}

void BasePrimes::getPrimesToCheck() {
    int toFilterCount = maxPrimesCount;
    while (primesToFilter[0] <= maxPrimeSqrt) {
        int passed = 0;
        int failIndex = 1;
        for (int i = 0; failIndex < toFilterCount; i++) {
            while (primesToFilter[i] * primesToFilter[0] > primesToFilter[failIndex]) {
                newPrimesToFilter[passed++] = primesToFilter[failIndex++];
                if (failIndex >= toFilterCount) break;
            }
            if (primesToFilter[i] * primesToFilter[0] == primesToFilter[failIndex]) {
                failIndex++;
            }
        }
        toFilterCount = passed;
        primes[primesCount++] = primesToFilter[0];
        int* tmp = primesToFilter;
        primesToFilter = newPrimesToFilter;
        newPrimesToFilter = tmp;
    }
    for (int i = 0; i < toFilterCount; i++) {
        primes[primesCount++] = primesToFilter[i];
    }
}
