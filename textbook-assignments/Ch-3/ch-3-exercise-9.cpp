#include <iostream>
#include <console.h>

using namespace std;

string removeDoubleLettersInSequence(string word);

/*
int main() {
    string h = "Bookkeeper";
    string d = "Coomer";
    string a = "Commitee";
    removeDoubleLettersInSequence(h);
    return 0;
}
*/

string removeDoubleLettersInSequence(string word) {
    int m = word.length() - 1;

    for(int i = 0; i <= m; i++) {
        if(word[i] == word[i+1]) {
            word.erase(i, 1);
            m--;
            i--;
        }
    }
    return word;
}


