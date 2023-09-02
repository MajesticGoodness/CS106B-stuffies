#include <iostream>
#include <console.h>
#include <cmath>

using namespace std;

double permutations(int n, int k);

int main(){
    double consoleOutput = permutations(4, 0);
    cout << consoleOutput << endl;
    return 0;
}

double permutations(int n, int k) {
    double result = 0;
    if (n >= k && k > 0) {
        double interimResult = 1;
        for (int i = 0; k > i; i++) {
            interimResult *= n--;
        }
        result = interimResult;
    }
    return result;
}
