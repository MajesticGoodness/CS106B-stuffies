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
        if (currentInput > greatestInt && currentInput != 0) {
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
