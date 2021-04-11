#pragma once

#include <cmath>

class BasePrimes
{
public:
	BasePrimes(int maxValue);
	~BasePrimes();
	void getPrimesToCheck();
    bool isPrime(int number);
private:
	int* primes;
	int* primesSquares;
	int primesCount = 0;
	int maxPrimesCount;
};

