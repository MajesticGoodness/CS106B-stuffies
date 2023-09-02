#include <iostream>

using namespace std;

string replaceAll(string original, const char occurance, const char replacement);
string replaceAll(string original, const string occurance, const string replacement);

/*
int main() {
    string a = "Sugardaddymandaddychilddaddycooldaddy";
    string b = "daddy";
    string c = "mommajaker";
    replaceAll(a, b, c);
    return 0;
}
*/
string replaceAll(string original, const char occurance, const char replacement) {
    int m = original.length() - 1;

    for(int i = 0; i <= m; i++) {
        if(original[i] == occurance) {
            original[i] = replacement;
        }
    }
    return original;
}


string replaceAll(string original, const string occurance, const string replacement) {
    int findPos = 0;

    while(true) {
        int j = original.find(occurance, findPos);
        if (j == string::npos) {
            break;
        }
        original.replace(j, occurance.length(), replacement);
        findPos = j + replacement.length();
    }
    return original;
}

/*
string replaceAll(string original, const string occurance, const string replacement) {
    int lastfindPos = 0;

    for(int i = 0; i <= original.length - 1; i += lastfindPos) {
        lastfindPos = original.find(occurance, i);
        if(lastfindPos != string::npos) {
            original.replace()
        }
    }
}
*/
