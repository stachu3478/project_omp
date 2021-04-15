#include "BasePrimes.h"

BasePrimes::BasePrimes(int minValue, int maxValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    
    primesToFilter = new char[maxValue + 1];
    
};

BasePrimes::~BasePrimes() {
    delete[] primesToFilter;
}

void BasePrimes::getPrimesToCheck() {
    
}
