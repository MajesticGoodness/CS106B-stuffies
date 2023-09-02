#include <iostream>
#include <console.h>
#include <cctype>

using namespace std;

string acronym(string seriesOfWords);

/*
int main() {
    string m = "Bake-n-Fake";
    acronym(m);
    return 0;
}
*/

string acronym(string seriesOfWords) {
    int m = seriesOfWords.length() - 1;
    string result;
    result += seriesOfWords[0];

    for(int i = 0; i <= m; i++) {
        if(!isalpha(seriesOfWords[i]) && isalpha(seriesOfWords[i+1]))
            result += seriesOfWords[i+1];
    }
    return result;
}
