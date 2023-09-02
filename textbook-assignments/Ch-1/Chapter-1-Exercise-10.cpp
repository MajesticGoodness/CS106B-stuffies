#include <iostream>
#include <cmath>
#include <console.h>

using namespace std;

bool divisibleByTwo(int n);
bool endOfFactoring(int n);
int divisionLoop(int n);
int findOddFactors(int n);
int divisionByTwo(int n);
int divisionByOddFactor(int n, int oddFactor);
void numberDecomposition(int n);

int main() {
    numberDecomposition(1337873432);
    return 0;
}

void numberDecomposition(int n) {
    while (true) {
        if (n == 0) {
            break;
        }
        if (divisibleByTwo(n)) {
           n = divisionByTwo(n);
        }
        else n = divisionByOddFactor(n, findOddFactors(n));
    }
}

bool divisibleByTwo(int n) {
    if (n % 2 == 0) {
        return true;
    }
    else return false;
}

int divisionByTwo(int n){
    n /= 2;
    cout << 2 << ", ";
    return n;
}

int findOddFactors(int n) {
    int oddFactor = 0;
    int squareRoot = sqrt(n);

    for (int i = 3; i <= squareRoot; i = i + 2) {
        if (n % i == 0) {
            oddFactor = i;
        }
    }
    return oddFactor;
}

int divisionByOddFactor(int n, int oddFactor){
    int divisionResult = 0;

    if (oddFactor == 0) {
        cout << n;
        return divisionResult;
    }
    divisionResult = n / oddFactor;
    cout << oddFactor << ", ";
    return divisionResult;
}


bool endOfFactoring(int n) {
    if (n == 1) {
        return true;
    }
    else return false;
}

