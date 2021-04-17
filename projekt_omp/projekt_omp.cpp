#include <omp.h>
#include <stdio.h>
#include <inttypes.h>
#include <algorithm>
#include "BasePrimes.h"

const int MIN = 2;
const int MAX = 50000000;
unsigned char result[MAX / 8 + 1];

void printResult(unsigned char* res = result) {
    int primeCount = 0;
    for (int i = MIN % 8, j = i + (MIN/8)*8; i < MAX - MIN + MIN % 8; i++, j++) {
        if (res[i >> 3] & (0b1 << (i & 0b111))) continue;
        if (++primeCount > 100) continue;
        if (primeCount % 10 == 0) printf("\n");
        printf("%d ", j);
    }
    printf("\nPrime count: %d\n", primeCount);
}

int main()
{
    double start, stop;
    start = omp_get_wtime();
    omp_set_num_threads(12);
    result[0] = 0b00000011;
    for (int i = 1; i <= MAX / 8; i++) result[i] = 0;
    int i, n;
    unsigned int maxPrimeSqrt = sqrt(MAX);
#pragma omp parallel for private(i, n)
    for (int d = 2; d <= maxPrimeSqrt; d++) {
        if (result[d >> 3] & (0b1 << (d & 0b111))) continue;
        for (i = MAX / d; i >= std::max(MIN / d, d); i--) {
            if (result[i >> 3] & (0b1 << (i & 0b111))) continue;
            n = i * d;
#pragma omp atomic
            result[n >> 3] |= 0b1 << (n & 0b111);
        }
        for (i = std::min((MAX / (d + 1)) / d, std::max(MIN / d, d) - 1); i >= d; i--) {
            if (result[i >> 3] & (0b1 << (i & 0b111))) continue;
            n = i * d;
#pragma omp atomic
            result[n >> 3] |= 0b1 << (n & 0b111);
        }
    }
    unsigned char* finalResult = result + MIN / 8;
    stop = omp_get_wtime();
    printResult(finalResult);
    printf("Czas przetwarzania wynosi %f sekund\n", stop - start);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
