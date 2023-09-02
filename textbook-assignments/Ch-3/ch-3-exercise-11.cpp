#include <iostream>
#include <cctype>

using namespace std;

string convertToLowerCase(string &truncatedString);
string truncate(string &original);
string reverse(string truncatedString);
bool isPalindrome(string original);

/*
int main() {
    string h = "Madam I'm Adam";
    isPalindrome(h);
    return 0;
}
*/
string truncate(string &original) {
    int m = original.length();

    for(int i = 0; i < m; i++) {
        if(!isalpha(original[i])) {
            original.erase(i, 1);
            m--;
            i--;
        }
    }
    return original;
}

string reverse(string truncatedString) {
    int m = truncatedString.length() - 1;
    string result;

    for(int i = m; 0 <= i; i--) {
        result += truncatedString[i];
    }
    return result;
}

string convertToLowerCase(string &truncatedString) {
    int m = truncatedString.length();

    for(int i = 0; i < m; i++) {
        if(isupper(truncatedString[i])) {
            truncatedString[i] = tolower(truncatedString[i]);
        }
    }
    return truncatedString;
}

bool isPalindrome(string original) {

    truncate(original);
    convertToLowerCase(original);

    if(original == reverse(original)) {
        return true;
    }
    return false;
}


