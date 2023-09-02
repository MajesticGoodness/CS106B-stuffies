#include <iostream>
#include <iomanip>
#include <cmath>
#include "console.h"

using namespace std;

int getInput();
void initValue();
void mainLoop(int currentInput, int secondLargestInt, int greatestInt);
void compareIntegers(int currentInput, int secondLargestInt, int greatestInt);

int main() {
    initValue();
  return 0;
}

void initValue() {
    int greatestInt = getInput();
    int secondLargestInt = 0;
    int currentInput = -1;

    mainLoop(currentInput, secondLargestInt, greatestInt);
}

int getInput() {
    int x = 0;
    cin >> x;
    return x;
}

void mainLoop(int currentInput, int secondLargestInt, int greatestInt) {
    while (currentInput != 0) {
        currentInput = getInput();
        compareIntegers(currentInput, secondLargestInt, greatestInt);
    }
}

void compareIntegers(int currentInput, int secondLargestInt, int greatestInt) {
    if (currentInput > greatestInt && secondLargestInt != 0){
        secondLargestInt = greatestInt;
        greatestInt = currentInput;
        mainLoop(currentInput, secondLargestInt, greatestInt);
    }
    if (currentInput > secondLargestInt && currentInput != greatestInt){
        secondLargestInt = currentInput;
        mainLoop(currentInput, secondLargestInt, greatestInt);
    }

}
