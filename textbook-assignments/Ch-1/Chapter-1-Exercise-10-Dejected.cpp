#include <iostream>
#include <console.h>

using namespace std;

void   divisiblityTest (int n);
const int isDivisible2(int n);

/*
const isDivisible3(int n);
const isDivisible5(int n);
const isDivisible7(int n);
*/
/*
void checkDivisiblity(int n);
*/


int main(){
    return 0;
}

/*
void divisiblityTest(int n) {
    switch (n) {
    case isDivisible2(n):
        cout << "you're a dick.";
        break;
    default:
        break;
    }
}
*/

const int isDivisible2(int n) {
    const int zero = 0;

    if (n % 2 == 0) {
        const int two = 2;
        return two;
    }
    else return zero;
}

/*
const isDivisible3(int n) {
    const zero = 0;

    if (n % 3 == 0) {
        const three = 3;
        return three;
    }
    else return zero;
}

const isDivisible5(int n) {
    const zero = 0;

    if (n % 5 == 0) {
        const five = 5;
        return five;
    }
    else return zero;
}

const isDivisible7(int n) {
    const zero = 0;

    if (n % 7 == 0) {
        const seven = 7;
        return seven;
    }
    else return zero;
}
*/


/*
void checkDivisiblity(int n) {

    if (isDivisible2(n)) {
        const two = 2;
        return two;
    }
    if (isDivisible3(n)) {
        const three = 3;
        return three;
    }
    if (isDivisible5(n)) {
        const five = 5;
        return five;
    }
    if (isDivisible7(n)) {
        const seven = 7;
        return seven;
    }


*/


