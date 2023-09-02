#include <iostream>
#include <iomanip>
#include <cmath>
#include "console.h"

using namespace std;

int computeSumOddIntegers (int endingInteger);

int main() {
    int sumOfIntegers = 0;
    int finalInteger = 16;
    sumOfIntegers = computeSumOddIntegers(finalInteger);
    cout << sumOfIntegers;
  return 0;
}

int computeSumOddIntegers(int endingInteger) {
    int result = 0;
    result = (endingInteger + 1)/2 * (endingInteger + 1)/2;
    return result;
}



