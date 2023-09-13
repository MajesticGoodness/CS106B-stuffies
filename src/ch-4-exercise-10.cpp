#include <iostream>
#include <ostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

void openReadFile(ifstream &inputFile);
void openWriteFile(ofstream &outputFile);
void processFile();
bool badStream(ifstream &inputFile);
bool endOfFile(ifstream &inputFile);
string repeatChar(char repeatedChar, int n);
string convertTabToSpace(int i);

int main() {
    processFile();
    cout << "Finished converting tabs to spaces";
    return 0;
}

void openReadFile(ifstream &inputFile) {
    string filename;
    string prompt = "Please enter input file: ";
    cout << prompt;
    cin >> filename;
    inputFile.open(filename);
    while(!inputFile) {
        cerr << "Unable to read file. Please try again. \n";
        inputFile.clear();
        cout << prompt;
        cin >> filename;
        inputFile.open(filename);
    }
}

void openWriteFile(ofstream &outputFile) {
    string prompt = "Please enter output file: ";
    string filename;
    cout << prompt;
    cin >> filename;
    outputFile.open(filename);
    while(!outputFile) {
        cerr << "Unable to read file. Please try again. \n";
        outputFile.clear();
        cout << prompt;
        cin >> filename;
        outputFile.open(filename);
    }
    return filename;
}

bool badStream(ifstream &inputFile) {
    if(inputFile.bad() || inputFile.fail()) {
        cerr << "encountered a file read error \n";
        return true;
    }
    return false;
}

bool endOfFile(ifstream &inputFile) {
    if(inputFile.eof()) {
        cout << "reached end of file. \n";
        return true;
    }
    return false;
}

bool getNewChar(ifstream &inputFile, char &ch) {
    inputFile.get(ch);
    if(endOfFile(inputFile)) {
        return false;
    }
    if(badStream(inputFile)) {
        return false;
    }
    return true;
}

void processFile() {
    ifstream inputFile;
    ofstream outputFile;
    char ch{};
    openReadFile(inputFile);
    openWriteFile(outputFile);

    for (int i = 0; getNewChar(inputFile, ch); i++) {
        if(i == 8) {
            i = 0;
        }
        if(ch == '\n') {
            i = -1;
        }
        if(ch == '\t') {
            string spaces;
            spaces = convertTabToSpace(i);
            outputFile << spaces;
            i = -1;
        }
        else outputFile << ch;
    }
}

string convertTabToSpace(int i) {
    int spaces{8 - i};
    string result;
    result = repeatChar(' ', spaces);
    return result;
}

string repeatChar(char repeatedChar, int n) {
    string result;
    for(int i = 0; i < n; i++) {
        result += repeatedChar;
    }
    return result;
}
