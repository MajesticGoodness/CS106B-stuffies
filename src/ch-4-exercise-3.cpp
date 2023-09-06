#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void findLongestLine(ifstream &inputFile, string &longestLine);
void userPrompt(string &prompt);
void getFileName(string &fileName);
void openFile(ifstream &inputFile, string &fileName);
void printLongestLine(string &longestLine);


int main() {
    ifstream inputFile;
    string fileName;
    string prompt;
    string longestLine;
    prompt = "Please enter a file name: ";

    userPrompt(prompt);
    getFileName(fileName);
    openFile(inputFile, fileName);
    findLongestLine(inputFile, longestLine);
    printLongestLine(longestLine);
    return 0;
}

void findLongestLine(ifstream &inputFile, string &longestLine) {
    string currentLine;

    while(inputFile) {
        getline(inputFile, currentLine);
        if (currentLine.length() > longestLine.length()) {
            longestLine = currentLine;
        }
    }
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

void printLongestLine(string &longestLine) {
    cout << "The longest line is:" << "\n";
    cout << longestLine;
}
