#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

void userPrompt(string &prompt);
void getFileName(string &fileName);
void openFile(ifstream &inputFile, string &fileName);
void countStuff(ifstream &inputFile);

int main() {
    ifstream inputFile;
    string fileName;
    string prompt;
    prompt = "Please enter a file name: ";

    userPrompt(prompt);
    getFileName(fileName);
    openFile(inputFile, fileName);
    countStuff(inputFile);
    return 0;
}

void countStuff(ifstream &inputFile) {
    string currentLine;
    double lineCount = 0;
    double wordCount = 0;
    double letterCount = 0;

    while(inputFile) {
        getline(inputFile, currentLine);
        lineCount++;

        for(int i = 0; i < currentLine.length(); i++ ) {
            int endOfWordPos = 0;
            if(!isspace(currentLine[i]) && isspace(currentLine[i+1])) {
                letterCount++;
            }

            if(!isspace(currentLine[i]) && !isspace(currentLine[i+1])) {
                wordCount++;
                endOfWordPos = currentLine.find(' ', i+1);
                if(endOfWordPos == -1) {
                    endOfWordPos = currentLine.length();
                }
                letterCount += endOfWordPos - i;
                i = endOfWordPos;
            }
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


