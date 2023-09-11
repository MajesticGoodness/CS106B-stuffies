#include <iostream>
#include <fstream>
#include <cctype>
#include <console.h>
#include <error.h>

using namespace std;

void removeStuffiesFromLine(string &currentLine, string &banishedLetters);
void openReadFile(ifstream &inputFile);
bool isSameChar(char ch, char ch1);
void openReadFile(ifstream &inputFile);
void openWriteFile(ofstream &outputFile, string &filename);
string getBanishedLetters();
void removeLetters();
void welcomeMsg();
void exitMsg();

int main() {
    welcomeMsg();
    removeLetters();
    exitMsg();
    return 0;
}

void removeStuffiesFromLine(string &currentLine, string &banishedLetters) {
    int m = currentLine.length();
    int n = banishedLetters.length();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char ch = currentLine[i];
            char ch1 = banishedLetters[j];

            if(!isalpha(ch)) {
                //do nothing
            }

            else if(isSameChar(ch, ch1)) {
                currentLine.erase(i, 1);
                m--;
                i--;
            }
        }
    }
}

bool isSameChar(char ch, char ch1) {
    if(toupper(ch) == toupper(ch1)) {
        return true;
    }
    return false;
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

void openWriteFile(ofstream &outputFile, string &filename) {
    string prompt = "Please enter output file: ";
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
}

void removeLetters() { //opens an input file stream as the source, then spits the resulting deletions to a new file.
    ifstream inputFile;
    ofstream outputFile;
    string outputFilename;
    string banishedLetters;

    openReadFile(inputFile);
    openWriteFile(outputFile, outputFilename);
    banishedLetters = getBanishedLetters();

    while(true) {
        string currentLine;
        std::getline(inputFile, currentLine);
        if(inputFile.bad() || inputFile.fail()) {
            cerr << "encountered a file read error \n";
            return;
        }

        if(currentLine == "") { //if we encounter nothing on a newline, it's just whitespace, which means we can just insert a newline.
            outputFile << "\n";
        }

        removeStuffiesFromLine(currentLine, banishedLetters); //remove unwanted letters from current line.
        outputFile << currentLine << "\n"; //take the current line with removed letters and insert it into the stream.

        if(inputFile.eof()) {
            break;
        }
    }
    cout << "The results have been saved to: " << outputFilename << "\n";
}

string getBanishedLetters() {
    string banishedLetters;
    while(true) {
        cout << "Please type the letters (in sequence) to be deleted from the input file. \n";
        cin >> banishedLetters;
        if(cin.good()){
            break;
        }
        if(cin.fail()) {
            cerr << "I wasn't able to quite catch that. Could you please try again? \n";
            banishedLetters = "";
        }
        if(cin.bad()) {
            error("Input was corrupted. Exiting program.");
            break;
        }
    }
    return banishedLetters;
}

void welcomeMsg() {
    cout << "This program will delete your choice of letters from a text document. \n";
    cout << "Example: our text document contains \"Goldilocks\" \n";
    cout << "An input of: \"go\" gives us back \"dilcks\" Note that capitalization is ignored. \n\n";
}

void exitMsg() {
    cout << "Program has exited. Thank you for using.";
}
