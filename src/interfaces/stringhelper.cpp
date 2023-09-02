#include <iostream>

using namespace std;

string removeCharacters(string originale, string deletionKey);
void removeCharactersInPlace(string &originale, string deletionKey);

string removeCharacters(string originale, string deletionKey) {
    int m = originale.length() - 1;
    int n = deletionKey.length() - 1;
    string result;

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if (originale[i] == deletionKey[j]) {
                result = originale.erase(i, 1);
                m--;
                i--;
            }
        }
    }
    return result;
}

void removeCharactersInPlace(string &originale, string deletionKey) {
    int m = originale.length() - 1;
    int n = deletionKey.length() - 1;

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(originale[i] == deletionKey[j]) {
                originale.erase(i, 1);
                m--;
                i--;
            }
        }
    }
}
