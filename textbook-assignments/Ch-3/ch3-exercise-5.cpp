#include <iostream>
#include <console.h>
#include <cctype>
#include <map.h>
#include <vector.h>
using namespace std;

int assignPointValue(char ch);
int getScramblePoints(string scrambleWord);

int assignPointValue(char ch) {
    switch (ch) {
    case 'A':
        return 1;
        break;
    case 'E':
        return 1;
        break;
    case 'I':
        return 1;
        break;
    case 'L':
        return 1;
        break;
    case 'N':
        return 1;
        break;
    case 'O':
        return 1;
        break;
    case 'R':
        return 1;
        break;
    case 'S':
        return 1;
        break;
    case 'T':
        return 1;
        break;
    case 'U':
        return 1;
        break;
    case 'D':
        return 2;
        break;
    case 'G':
        return 2;
        break;
    case 'B':
        return 3;
        break;
    case 'C':
        return 3;
        break;
    case 'M':
        return 3;
        break;
    case 'P':
        return 3;
        break;
    case 'F':
        return 4;
        break;
    case 'H':
        return 4;
        break;
    case 'V':
        return 4;
        break;
    case 'W':
        return 4;
        break;
    case 'Y':
        return 4;
        break;
    case 'K':
        return 5;
        break;
    case 'J':
        return 8;
        break;
    case 'X':
        return 8;
        break;
    case 'Q':
        return 10;
        break;
    case 'Z':
        return 10;
        break;
    default:
        return 0;
        break;
    }
}

/*
int main() {
    string scrambleWord = "FARM";
    getScramblePoints(scrambleWord);
    return 0;
}
*/

int getScramblePoints(string scrambleWord) {
    int m = scrambleWord.length() - 1;
    int totalPoints = 0;

    for(int i = 0; i <= m; i++) {
        if(isupper(scrambleWord[i])) {
            totalPoints += assignPointValue(scrambleWord[i]);
        }
    }
    return totalPoints;
}

/*
void initLetterValues();
*/

/*
void initLetterValues() {
    vector<int> letterValues = {
        1, // A
        3, // B
        3, // C
        2, // D
        1, // E
        4, // F
        2, // G
        4, // H
        1, // I
        8, // J
        5, // K
        1, // L
        3, // M
        1, // N
        1, // O
        3, // P
        10,// Q
        1, // R
        1, // S
        1, // T
        1, // U
        4, // V
        4, // W
        8, // X
        4, // Y
        10,// Z

    };

}
*/
