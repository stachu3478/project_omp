#include <omp.h>
#include <stdio.h>
#include "BasePrimes.h"

const int MIN = 2;
const int MAX = 200000000;
char result[MAX - MIN]{ true };

void printResult() {
    int primeCount = 0;
    for (int i = 0, j = MIN; j < MAX; i++, j++) {
        if (!result[i]) continue;
        // if (++primeCount > 100) continue;
        /*if (*/++primeCount; /*% 10 == 0) printf("\n");*/
        //printf("%d ", j);
    }
    printf("\nPrime count: %d\n", primeCount);
}

int main()
{
    double start, stop;
    start = omp_get_wtime();
    BasePrimes basePrimes(MIN, MAX);
    //omp_set_num_threads(12);
    //basePrimes.getPrimesToCheck();
//#pragma omp parallel for
    basePrimes.getPrimesToCheck();
    //int* primes = basePrimes.get();
    //for (int i = 0; i < basePrimes.length(); i++) {
    //    printf("%d, ", primes[i]);
    //}
    stop = omp_get_wtime();
    printf("\nPrime count: %d\n", basePrimes.length());
    printf("Czas przetwarzania wynosi %f sekund\n", stop - start);
    //printResult();
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
