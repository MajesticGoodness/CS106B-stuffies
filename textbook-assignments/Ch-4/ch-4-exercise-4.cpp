#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

void userPrompt(string &prompt);
void getFileName(string &fileName);
void openFile(ifstream &inputFile, string &fileName);
void countStuff(ifstream &inputFile, int &lineCount, int &wordCount, int &letterCount);
void printStuff(int lineCount, int wordCount, int letterCount);

int main() {
    ifstream inputFile;
    string fileName;
    string prompt;
    int lineCount = 0;
    int wordCount = 0;
    int letterCount = 0;
    prompt = "Please enter a file name: ";

    userPrompt(prompt);
    getFileName(fileName);
    openFile(inputFile, fileName);
    countStuff(inputFile, lineCount, wordCount, letterCount);
    printStuff(lineCount, wordCount, letterCount);
    return 0;
}

void countStuff(ifstream &inputFile, int &lineCount, int &wordCount, int &letterCount) {
    string currentLine;
    string previousLine;
    ios_base::iostate state;


    while(inputFile) {
        getline(inputFile, currentLine);
        state = inputFile.rdstate(); // including here to see what the input stream's state is when debugging.
        if(inputFile.bad()) {
            cerr << "program encountered a read file error \n";
            break;
        }
        if(inputFile.fail()) {
            break;
        }

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
        if(inputFile.eof()) return;
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

void printStuff(int lineCount, int wordCount, int letterCount) {
    cout << right;
    cout << "Number of lines: " << lineCount << "\n";
    cout << "Number of letters: " << letterCount << "\n";
    cout << "Number of words: " << wordCount << "\n";
}


