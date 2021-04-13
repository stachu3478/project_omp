#pragma once

#include <cmath>
#include <algorithm>    // std::max



class BasePrimes
{
public:
	BasePrimes(int minValue, int maxValue);
	~BasePrimes();
	void getPrimesToCheck();
	char* get() { return primesToFilter + minValue; };
private:
	char* primesToFilter;
	int primesCount = 0;
	int maxPrimeSqrt;
	int minValue;
	int maxValue;
};

