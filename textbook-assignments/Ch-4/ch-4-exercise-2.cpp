#include <iostream>
#include <iomanip>
#include <cmath>
#include <console.h>

using namespace std;
double windChill(double temp, double windSpeed);
void printOutRows();
void printOutTempRow(int currentWindspeed, int currentTemp, int n);
string repeatChar(char repeatedChar, int n);

const double TEMP_CONSTANT = 35.74;
const double AIR_TEMP_CONSTANT = 0.6215;
const double TEMP_CONSTANT2 = 35.75;
const double AIR_TEMP_CONSTANT2 = 0.4275;
const int TEMP_TABLE_WIDTH = 4;

int main() {
    //double cuteResult = 0.0;
    //cuteResult = windChill(30.0, 0);
    printOutRows();
    return 0;
}

double windChill(double temp, double windSpeed) {
    double result = 0.0;
    double windSpeedFactor = 0.0;
    double additionSegment = 0.0;
    double subtractionSegment = 0.0;

    if(temp > 40.0) {
        cerr << "At temperatures greater than 40 degrees Fahrenheit, there is no wind chill.";
        return result;
    }

    windSpeedFactor = pow(windSpeed, 0.16);
    additionSegment = TEMP_CONSTANT + AIR_TEMP_CONSTANT * temp;
    subtractionSegment = -TEMP_CONSTANT2 * windSpeedFactor + AIR_TEMP_CONSTANT2 * temp * windSpeedFactor;

    result = additionSegment + subtractionSegment;

    return result;
}

void printOutRows() {
    string xAxis = "Temperature (F)";
    string yAxis = "Windspeed (mph)";
    const int W = TEMP_TABLE_WIDTH;
    int currentTemp = 0;
    int startTemp = 40;
    int endTemp = -45;
    int n = 0;
    int currentWindSpeed = 0;
    int startWindSpeed = 5;
    int endWindSpeed = 60;
    int m = 0;
    n = (startTemp - endTemp) / 5;
    m = (endWindSpeed - startWindSpeed) / 5;
    currentTemp = startTemp;
    currentWindSpeed = startWindSpeed;
    //print out x-axis
    cout << setw(yAxis.length() + 1) << repeatChar(' ', yAxis.length() + 1) << "|" << xAxis << "\n";
    //print out y-axis and temp values from 40 to 0.
    cout << setw(yAxis.length() + 1) << yAxis << "|";
    //need a for loop here to from temp 40 to 0 (in increments of 5.)
    cout << left;


    for(int i = 0; i <= n; i++) {
        cout << setw(W) << currentTemp << "|";
        currentTemp -= 5;
    }

    //wanna repeatChar('-', yAxis.length() +1), followed by a "|"
    //then just do repeatChar('-', 3) followed by a "|" in a for loop n times

    cout << "\n" << setw(yAxis.length() + 1) << repeatChar('-', yAxis.length() + 1) << "|";

    for(int i = 0; i <= n; i++) {
        cout << setw(W) << repeatChar('-', W) << "|";
    }
    cout << "\n";
    currentTemp = startTemp;
    for(int i = 0; i <= m; i++) {
        cout << repeatChar(' ', (yAxis.length() + 1) / 2) << setw((yAxis.length() + 1) / 2) << currentWindSpeed << "|";
        printOutTempRow(currentWindSpeed, currentTemp, n);
        cout << "\n";
        currentWindSpeed += 5;
    }
}

string repeatChar(char repeatedChar, int n) {
    string result;
    for(int i = 0; i < n; i++) {
        result += repeatedChar;
    }
    return result;
}

void printOutTempRow(int currentWindSpeed, int currentTemp, int n){
    const int W = TEMP_TABLE_WIDTH;
    for(int i = 0; i <= n; i++) {
        cout << setw(W) << int(windChill(currentTemp, currentWindSpeed)) << "|";
        currentTemp -= 5;
    }
}

    //row 0 == row of column names
    //row 1 == seperator
    //row 2 == actual start of rows
    //let's start at row 2 in this function.
    //would like to set the column width to equal the actual data output
    //then, using the same column width, we set the the table headers,
    //that way the table headers will always be long enough
    //numbers don't really have a .length method that I can call though, unless I convert them to strings first.
    //in general we can just check if input data length > table header length. set the setw to whichever is bigger.
    /* I kinda want our table to look like this:
     *
                |Temperature (F)
Windspeed (mph) |40 |35 |
----------------|---|---|
      5         |35 |29 |
      10        |26 |25 |
      15        |21 |20 |
      20        |19 |17 |
*/

