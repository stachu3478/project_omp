#pragma once

#include <cmath>

class BasePrimes
{
public:
	BasePrimes(int maxValue);
	void getPrimesToCheck();
    bool isPrime(int number);
private:
	int* primes;
	int primesCount = 0;
	int maxPrimesCount;
};

