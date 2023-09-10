#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;
char getRandomChar();
void getNewLine(ifstream &inputFile);
void getFileName(string &fileName);
void userPrompt(string &prompt);
void openFile(ifstream &inputFile, string &fileName);

int main() {
    ifstream inputFile;
    string fileName;
    string prompt;
    prompt = "Please enter a file name: ";

    userPrompt(prompt);
    getFileName(fileName);
    openFile(inputFile, fileName);
    getNewLine(inputFile);
    getNewLine(inputFile);
    return 0;
}

char getRandomChar() {
    char h;
    h = ' ';
    return h;
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


void getNewLine(ifstream &inputFile) {
    string currentLine = "";
    ios_base::io_state state;

    std::getline(inputFile, currentLine);
    state = inputFile.rdstate(); // including here to see what the input stream's state is when debugging.

    if(inputFile.bad() || inputFile.fail() || inputFile.eof()) {
        cerr << "program encountered a read file error \n";
        return;
    }
}

/* We're going to read from a file using getline.
 * For now, let's just replace every char in the line with 'a'.
 * Making sure to leave nonalpha characters intact.
 *
 * We'd like to print these new lines to the console. Should we just pass currentLineChanged to a print function?
 *
 * What we'd like then is a funtion that takes a string (currentLine) and changes its characters (a for now).
 */
