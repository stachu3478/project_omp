#pragma once

#include <cmath>

class BasePrimes
{
public:
	BasePrimes(int minValue, int maxValue);
	~BasePrimes();
	void getPrimesToCheck();
	int* get() { return primes; };
	int length() { return primesCount; };
private:
	int* primes;
	int* primesToFilter;
	int* newPrimesToFilter;
	int primesCount = 0;
	int maxPrimesCount;
	int maxPrimeSqrt;
};

