/*

#include <iostream>
#include <iomanip>
#include <cmath>
#include "console.h"

using namespace std;

void mainLoop(int x);
void loopCaller();
void printBiggerInt(int x);
int initValue();
int getInput();
int getBiggerInteger(int x, int y);



int main() {
    loopCaller();
  return 0;
}

int getInput() {
    int x = 0;
    cin >> x;
    return x;
}

void mainLoop(int x) {
    //int prevInput = x;
    int greatestInt = x;
    int currentInput = -1;
    while (currentInput != 0) {
        currentInput = getInput();
        if (currentInput > greatestInt) {
            greatestInt = currentInput;
        }
    }
    printBiggerInt(greatestInt);
}

int initValue() {
    int x = 0;
    x = getInput();
    return x;
}

// Call our main loop with an initialized integer value.
void loopCaller() {
    int x = 0;
    x = initValue();
    mainLoop(x);
}

int getBiggerInteger(int x, int y) {
    if (x < y)
        return y;
    else
        return x;
}

void printBiggerInt(int x) {
    cout << "Our biggest integer so far is: " << x;

}

void mainLoop(int x) {
    //int prevInput = x;
    int greatestInt = x;
    int secondLargestInt = 0;
    int currentInput = -1;

    while (currentInput != 0) {
        currentInput = getInput();
        if (currentInput > greatestInt && currentInput != 0) {
            secondLargestInt = greatestInt;
            greatestInt = currentInput;
        }
    }
    printBiggerInt(greatestInt);
}


void mainLoop(int x);
void loopCaller();
void printBiggerInt(int x);
int initValue();
int getInput();
int getBiggerInteger(int x, int y);
int compareIntegers(int currentInput, int greatestInt, int secondLargestInt);



int main() {
    loopCaller();
  return 0;
}

int getInput() {
    int x = 0;
    cin >> x;
    return x;
}

void mainLoop(int x) {
    //int prevInput = x;
    int greatestInt = x;
    int secondLargestInt = 0;
    int currentInput = -1;

    while (currentInput != 0) {
        currentInput = getInput();
        if (currentInput != 0) {
            compareIntegers(currentInput, greatestInt, secondLargestInt);
        }
    }
    printBiggerInt(greatestInt);
}

int initValue() {
    int x = 0;
    x = getInput();
    return x;
}

// Call our main loop with an initialized integer value.
void loopCaller() {
    int x = 0;
    x = initValue();
    mainLoop(x);
}

int getBiggerInteger(int x, int y) {
    if (x < y)
        return y;
    else
        return x;
}

void printBiggerInt(int x) {
    cout << "Our biggest integer so far is: " << x;
}

int compareIntegers(int currentInput, int greatestInt, int secondLargestInt) {

    switch (currentInput) {
    case (currentInput > greatestInt):
        greatestInt = currentInput;
        break;
    default:
        break;
    }
}

*/
