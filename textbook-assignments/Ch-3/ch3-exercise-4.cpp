#include <iostream>
#include <console.h>
#include <cctype>

using namespace std;

string capFirstLetter(string h);
string lowerLetters(string h);
string capitalize(string h);

int main(){
    string h = "RAWRMaNl";
    h = capitalize(h);
    return 0;
}

string capitalize(string h){
    h = capFirstLetter(h);
    h = lowerLetters(h);
    return h;
}

string capFirstLetter(string h){
    if(islower(h[0])) {
        h[0] = toupper(h[0]);
    }
    return h;
}

string lowerLetters(string h){
    int m = h.length() - 1;
    for(int i = 1; i <= m; i++){
        if(isupper(h[i])) {
            h[i] = tolower(h[i]);
        }
    }
    return h;
}

