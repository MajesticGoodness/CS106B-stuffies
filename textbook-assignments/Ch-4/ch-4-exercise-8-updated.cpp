#include <iostream>
#include <ostream>
#include <fstream>
#include <cctype>
#include <string>


//This is a program to remove comments from files.
//It supports removing these two types of comments:
//Comments that are indicated with \//
//And comments that are begin with a forward flash (/) followed by an asteriks (*),
//and then terminated with an asterik (*), followed by a forward slash (/)
//At the moment, it ignores newlines that only consist of whitespace.
//Lots of room for improvement here.

using namespace std;

void getFileName(string &fileName);
void userPrompt(string &prompt);
void openFile(ifstream &inputFile, string &fileName);
void openFile(ofstream &outputFile, string &fileName);
void processLines(ifstream &inputFile, ostream os);
void removeComments(ifstream &inputFile, ostream &os);
void removeCommentsFromLine(ostream &os, string &currentLine);

int main() {
    ifstream inputFile;
    ofstream outputFile;
    string fileName;
    string prompt;
    prompt = "Please enter a file name for input: ";
    userPrompt(prompt);
    getFileName(fileName);
    openFile(inputFile, fileName);

    prompt = "Please enter a file name for output: ";
    userPrompt(prompt);
    getFileName(fileName);
    openFile(outputFile, fileName);
    removeComments(inputFile, outputFile);
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

void openFile(ofstream &outputFile, string &fileName) {
    outputFile.open(fileName);
    while(!outputFile) {
        string failurePrompt = "Please try again: ";
        cerr << "Unable to open file. \n";
        userPrompt(failurePrompt);
        getFileName(fileName);
        outputFile.clear();
        outputFile.open(fileName);
    }
}

void removeComments(ifstream &inputFile, ostream &os) {
    while(true) {
        string currentLine;
        std::getline(inputFile, currentLine);
        if(inputFile.bad() || inputFile.fail()) {
            cerr << "encountered a file read error \n";
            break; //our stream has gone bad for some reason, abandon the loop.
        }
        removeCommentsFromLine(os, currentLine);
        if(inputFile.eof()) {
            return;
        }
    }
}

void removeCommentsFromLine(ostream &os, string &currentLine) {
    int m = currentLine.length();
    bool writeToBuffer = true;
    bool wroteToBuffer = false;
    static bool persist = false;

    for(int i = 0; i < m; i++) {
        if(currentLine[i] == '/' && i + 1 <= m) {
            if(currentLine[i+1] == '*') {
                writeToBuffer = false;
                persist = true;
                //case one, keep deleting until we encounter */
            }
            if(currentLine[i+1] == '/') {
                writeToBuffer = false;
                //case two, but delete only up to the end of the current line.
            }
        }
        if(currentLine[i] == '*' && i + 1 <= m) {
            if(currentLine[i+1] == '/') {
                persist = false;
                writeToBuffer = true;
                i += 2;
            }
        }
        if(writeToBuffer && i < m && !persist) {
            wroteToBuffer = true;
            os << currentLine[i]; //write current char to the buffer.
        }
    }
    if(currentLine == "") {
        os << "\n";
    }
    if(wroteToBuffer) {
        os << '\n';
    }
}
