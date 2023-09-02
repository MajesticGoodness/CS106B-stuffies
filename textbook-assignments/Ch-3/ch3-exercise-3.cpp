#include <iostream>
#include <console.h>
#include <error.h>

using namespace std;

string subString(string str, int pos, int n);
string subString(string str, int pos);

/*
int main() {
    string h = "heckyeahfudge";
    subString(h, 2, 6);
    string check = h.substr(2, 6);
    return 0;
}
*/

string subString(string str, int pos) {
    int m = str.length() - 1;
    int distance = m - pos;
    string result;

    for(int i = 0; i <= distance; i++) {
        result += str[pos++];
    }
    return result;
}


string subString(string str, int pos, int n) {
    int m = str.length() - 1;
    int distance = m - pos;
    string result;

    if(m < pos) {
        ErrorException("Aw jeez, the string is shorter than the beginning index position in subString()");
    }
    if(distance < 0) {
        distance = abs(distance);
    }
    for(int i = 0; i < n && i <= distance; i++) {
        result += str[pos++];
    }
    return result;
}
