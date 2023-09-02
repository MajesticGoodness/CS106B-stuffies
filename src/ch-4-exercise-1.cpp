#include <iostream>
#include <iomanip>
#include <cmath>
#include <console.h>

using namespace std;

void tabulateSinValues(double sinValues[], int maxSize);
void tabulateCosValues(double cosValues[], int maxSize);
void tabulateTanValues(double tanValues[], int maxSize);
void calcTrigValues(int startThetaDegrees, int endThetaDegrees, double trigValues[], int &trigValuesSize);
void printOutTrigValues();
void printHeader(string columns[], int actualColumnSize);
void fillColumns(string columns[], const int MAX_SIZE, int &actualColumnSize);
void printRows(string columns[], int actualColumnSize, double trigValues[], int trigValuesSize);
string repeatChar(char repeatedChar, int n);

const double PI = 3.14159265358979323846;

int main() {
    //calcTrigValues(90, -90);
    //printOutTrigValues();
    const int MAX_COLUMNS = 90;
    const int MAX_ROWS = 100000;
    int actualColumnSize = 0;
    int trigValuesSize = 0;
    string columns[MAX_COLUMNS];
    double trigValues[MAX_ROWS];

    calcTrigValues(90, -90, trigValues, trigValuesSize);
    fillColumns(columns, MAX_COLUMNS, actualColumnSize);
    printHeader(columns, actualColumnSize);
    printRows(columns, actualColumnSize, trigValues, trigValuesSize);
    return 0;
}
/*
void tabulateSinValues(double sinValues[], int maxSize) {
    double theta = -PI/2;
    double incrementFactor = PI/12;

    for(int i = 0; i < maxSize; i++) {
        sinValues[i] = sin(theta);
        if(int(theta / incrementFactor) == -1 || 1) {
            theta = 0;
        }
        else theta += incrementFactor;
    }
}

void tabulateCosValues(double cosValues[], int maxSize) {
    double theta = -PI/2;
    double incrementFactor = PI/12;

    for(int i = 0; i < maxSize; i++) {
        cosValues[i] = cos(theta);
        if(int(theta / incrementFactor) == -1 || 1) {
            theta = 0;
        }
        else theta += incrementFactor;
    }
}

void tabulateTanValues(double tanValues[], int maxSize) {
    double theta = -PI/2;
    double incrementFactor = PI/12;

    for(int i = 0; i < maxSize; i++) {
        tanValues[i] = tan(theta);
        if(int(theta / incrementFactor) == -1 || 1) {
            theta = 0;
        }
        else theta += incrementFactor;
    }
}
*/
void calcTrigValues(int startThetaDegrees, int endThetaDegrees, double trigValues[], int &trigValuesSize) {
    int n = 0;
    double startThetaRadians = 0.0;
    double theta = 0.0;
    int thetaDegrees = startThetaDegrees;
    double incrementFactorRadians = PI/12;
    int incrementFactorDegrees = 15;
    double sinResult = 0.0;
    double cosResult = 0.0;

    n = (startThetaDegrees - endThetaDegrees) / 15;
    startThetaRadians = startThetaDegrees * (PI/180);
    theta = startThetaRadians;

    if(endThetaDegrees < startThetaDegrees) {
        incrementFactorRadians *= -1.0;
        incrementFactorDegrees *= -1;
    }

    for(int i, j = 0; i <= n; i++) {
        sinResult = sin(theta);
        cosResult = cos(theta);

        trigValues[j++] = thetaDegrees;
        trigValues[j++] = sinResult;
        trigValues[j++] = cosResult;
        trigValuesSize += 3;

        theta += incrementFactorRadians;
        thetaDegrees += incrementFactorDegrees;

        if(0.0 < theta && theta < 0.1E-7) {
            theta = 0.0;
        }
        if(-0.1E-7 < theta && theta < 0.0){
            theta = 0.0;
        }
    }
}

void printOutTrigValues() {
    cout << setw(7) << "   90" << "|";
    cout << setw(13) << " 1.0000000 " << "|";
    cout << setw(12) << " 1.0000000 " << "|" << "\n";
}

void printHeader(string columns[], int actualColumnSize) {
    int totalColumnWidth = 0;
    cout << left;

    for(int i = 0; i < actualColumnSize; i++ ) {
        cout << setw(columns[i].length()) << columns[i] << " |";
        totalColumnWidth += columns[i].length();
    }
    cout << "\n";
    for(int i = 0; i < actualColumnSize; i++) {
        cout << setw(columns[i].length()) << repeatChar('-', columns[i].length() + 1) << "|";
    }
    cout << "\n";
}

void printRows(string columns[], int actualColumnSize, double trigValues[], int trigValuesSize) {
    //0 = theta
    //1 = sin
    //2 == cos
    //3 == theta again
    //4 == sin again
    //5 == cos again
    //6 == theta again, etc
    for(int i = 0; i < trigValuesSize; ) {
        for(int j = 0; j < actualColumnSize; j++) {
            if(j + i == 0 || i % 3 == 0) {
                cout << noshowpoint;
            }
            else {
                cout << showpoint;
            }
            cout << setw(columns[i].length()) << setprecision(7) << trigValues[j+i] << " |";
        }
        cout << "\n";
        i += 3;
    }
}

void fillColumns(string columns[], const int MAX_SIZE, int &actualColumnSize){
    int colNumbers = 0;

    cout << "How many columns would you like? : ";
    cin >> colNumbers;
    if(colNumbers > MAX_SIZE) {
        cout << "Too many columns! Only a maximum of " << MAX_SIZE << " is supported." << "\n";
        return;
    }
    for(int i = 1; i <= colNumbers; i++) {
        cout << "Please name column " << i << ": ";
        cin >> columns[i-1];
    }
    cout << "\n";
    actualColumnSize = colNumbers;
}

string repeatChar(char repeatedChar, int n) {
    string result;
    for(int i = 0; i < n; i++) {
        result += repeatedChar;
    }
    return result;
}

