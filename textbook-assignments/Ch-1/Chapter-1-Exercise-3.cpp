#include <iostream>
#include <iomanip>
#include <cmath>
#include "console.h"

using namespace std;

// starting from the number 1, give me an integer greater than
// that, and i'll give you back the sum of all the numbers between them
// i.e., what is the sum of the numbers between 1 and 50?
// we can make this is in general as well, for any integers x and y
// let's just focus on the basic case for now.

int computeSeriesSum(int end);
int computeSeriesSum(int start, int end);

int main() {
    int end = 100;
    int result = 0;
    result = computeSeriesSum(end);
    cout << result;
  return 0;
}

int computeSeriesSum(int end) {
    int sum = 0;
    sum = ((end * end) + end)/2;
    return sum;
}



