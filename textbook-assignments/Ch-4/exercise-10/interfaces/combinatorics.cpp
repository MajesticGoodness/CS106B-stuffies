#include <iostream>
#include <console.h>

using namespace std;

double permutations(int n, int k);
double combinations(int n, int k);
double boundedFactorial(int n, int k);

/* computes a factorial, but only up to a bound defined by k.
 * boundedFactorial(52, 2) computes:
 * 52 * 51.
 * boundedFactorial(52, 3) computes:
 * 52 * 51 * 50.
 */

double boundedFactorial(int n, int k) {
    double result = 1;

    if (n >= k) {
        for (int i = 0; k > i; i++) {
            result *= n--;
        }
    }
    return result;
}


double permutations(int n, int k) {
    double result = 0;

    if (n >= k) {
        result = boundedFactorial(n, k);
    }
    return result;
}

double combinations(int n, int k) {
    double permutationResult = 0;
    double result = 0;
    double kFact = 0;
    int kBound = 0;

    if (n >= k) {
        if (k > n / 2) {
            kBound = n - k;
            permutationResult = permutations(n, kBound);
        }
        else {
            kBound = k;
            permutationResult = permutations(n, kBound);
        }
        kFact = boundedFactorial(kBound, kBound);
        result = permutationResult / kFact;
    }
    return result;
}
