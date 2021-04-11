#include "BasePrimes.h"

BasePrimes::BasePrimes(int maxValue) {
    maxPrimesCount = sqrt(maxValue);
    primes = new int[maxPrimesCount];
};

void BasePrimes::getPrimesToCheck() {
    for (int d = 2; d <= maxPrimesCount; d++) {
        if (isPrime(d)) {
            primes[primesCount++] = d;
        }
    }
}

bool BasePrimes::isPrime(int number) {
    for (int i = 0; i < primesCount && primes[i] <= sqrt(number); i++) {
        if (number % primes[i] == 0) {
            return false;
        }
    }
    return true;
}