#include <iostream>
#include <console.h>

using namespace std;

int getInput();
void findLargestAndSecondLargest();

int main() {
    findLargestAndSecondLargest();
    return 0;
}

int getInput() {
    int x = 0;
    cin >> x;
    return x;
}

void findLargestAndSecondLargest() {
    int greatestInt = 0;
    int secondLargestInt = 0;
    int currentInput = -1;

    while (currentInput != 0) {
        currentInput = getInput();

        if (currentInput > greatestInt) {
            secondLargestInt = greatestInt;
            greatestInt = currentInput;
        } else if (currentInput > secondLargestInt && currentInput != greatestInt) {
            secondLargestInt = currentInput;
        }
    }

    cout << "Largest integer: " << greatestInt << endl;
    cout << "Second largest integer: " << secondLargestInt << endl;
}
