#include <console.h>
#include <iostream>

using namespace std;

string trimFront(string str);
string trimBack(string str);
string trimString(string str);

string trimString(string str){
    str = trimFront(str);
    str = trimBack(str);
    return str;
}

string trimFront(string str){
    int n = str.length();
    string result;
    for(int i = 0; i < n; i++)
        if (str[i] != ' ') {
            result = str.substr(i);
            break;
        }
    return result;
}

string trimBack(string str) {
    int m = str.length() - 1;
    string result;
    for(int i = m; i != 0; i--) {
        if(str[i] != ' ') {
            i++;
            result = str.substr(0, i);
            break;
        }
    }
    return result;
}

