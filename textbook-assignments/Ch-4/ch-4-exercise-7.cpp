#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <random.h>

/*
 * This program takes in a text file and replaces its alpha characters with other, random alpha characters.
 * Its purpose is to mimic how typesetters might look at a piece of text: they're not so interested in its contents, but rather, how it's formatted.
 */

using namespace std;
void getFileName(string &fileName);
void userPrompt(string &prompt);
void openFile(ifstream &inputFile, string &fileName);
void processLines(ifstream &inputFile, string &currentLine);
void swapChars(string &currentLine);
char randAlphaChar(char ch);
void printOutLine(string &currentLine);

int main() {
    ifstream inputFile;
    string fileName;
    string prompt;
    string currentLine;
    prompt = "Please enter a file name: ";

    userPrompt(prompt);
    getFileName(fileName);
    openFile(inputFile, fileName);
    processLines(inputFile, currentLine);
    return 0;
}

void userPrompt(string &prompt) {
    cout << prompt;
}

void getFileName(string &fileName) {
    getline(cin, fileName);
}

void openFile(ifstream &inputFile, string &fileName) {
    inputFile.open(fileName);
    while(!inputFile) {
        string failurePrompt = "Please try again: ";
        cerr << "Unable to open file. \n";
        userPrompt(failurePrompt);
        getFileName(fileName);
        inputFile.clear();
        inputFile.open(fileName);
    }
}

void processLines(ifstream &inputFile, string &currentLine) {
    while(true) {
        std::getline(inputFile, currentLine);
        if(inputFile.bad() || inputFile.fail()) {
            cerr << "encountered a file read error \n";
            break; //our stream has gone bad for some reason, abandon the loop.
        }
        swapChars(currentLine);
        printOutLine(currentLine);
        if(inputFile.eof()) {
            return;
        }
    }
}

void swapChars(string &currentLine) {
    int m = currentLine.length();
    char ch = ' ';
    for(int i = 0; i < m; i++) {
        if(isalpha(currentLine[i])) {
            ch = currentLine[i];
            currentLine[i] = randAlphaChar(ch);
        }
    }
}

char randAlphaChar(char ch) {
    int rando = 0;
    char failed = '0'; //return 0 char if somehow both of our cases were not a match. function should only take alpha chars.
    char lowerCaseAlpha = ' ';
    char upperCaseAlpha = ' ';
    rando = randomInteger(0, 25);

    if(isupper(ch)) {
        upperCaseAlpha = 90 - rando;
        return upperCaseAlpha;
    }
    if(islower(ch)) {
        lowerCaseAlpha = 122 - rando;
        return lowerCaseAlpha;
    }
    return failed;
}

void printOutLine(string &currentLine) {
    cout << currentLine << "\n";
}


/* We're going to read from a file using getline.
 * For now, let's just replace every char in the line with 'a'.
 * Making sure to leave nonalpha characters intact.
 *
 * We'd like to print these new lines to the console. Should we just pass currentLineChanged to a print function?
 *
 * What we'd like then is a funtion that takes a string (currentLine) and changes its characters (a for now).
 */
