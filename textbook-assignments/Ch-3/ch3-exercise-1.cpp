#include <iostream>
#include <console.h>
#include <strlib.h>

using namespace std;

bool stringEndsWith(string str, string suffix);

bool stringEndsWith(string str, string suffix) {
    int n = str.length() - 1;
    int m = suffix.length() - 1;
    bool result = false;

    if (m > n) {
        return false;
    }
    for (int i = 0; i <= m; ) {
        if (str[n] == suffix[m]) {
            result = true;
            n--;
            m--;
        }
        else {
            result = false;
            break;
        }
    }
    return result;
}



