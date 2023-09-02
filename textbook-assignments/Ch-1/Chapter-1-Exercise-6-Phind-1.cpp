#include <iostream>
#include <console.h>

using namespace std;

int getInput();
void initializeValues(int& greatestInt, int& secondLargestInt);
void compareIntegers(int currentInput, int& secondLargestInt, int& greatestInt);

int main() {
    int greatestInt, secondLargestInt;
    initializeValues(greatestInt, secondLargestInt);

    int currentInput;
    while (true) {
        currentInput = getInput();
        if (currentInput == 0) {
            break;
        }
        compareIntegers(currentInput, secondLargestInt, greatestInt);
    }

    cout << "Largest integer: " << greatestInt << endl;
    cout << "Second largest integer: " << secondLargestInt << endl;

    return 0;
}

int getInput() {
    int currentInput;
    cout << "Enter an integer (0 to exit): ";
    cin >> currentInput;
    return currentInput;
}

void initializeValues(int& greatestInt, int& secondLargestInt) {
    greatestInt = 0;
    secondLargestInt = 0;
}

void compareIntegers(int currentInput, int& secondLargestInt, int& greatestInt) {
    if (currentInput > greatestInt) {
        secondLargestInt = greatestInt;
        greatestInt = currentInput;
    } else if (currentInput > secondLargestInt) {
        secondLargestInt = currentInput;
    }
}

