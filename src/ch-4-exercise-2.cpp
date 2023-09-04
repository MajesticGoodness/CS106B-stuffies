#include <iostream>
#include <iomanip>
#include <cmath>
#include <console.h>

using namespace std;
double windChill(double temp, double windSpeed);

const double TEMP_CONSTANT = 35.74;
const double AIR_TEMP_CONSTANT = 0.6215;
const double TEMP_CONSTANT2 = 35.75;
const double AIR_TEMP_CONSTANT2 = 0.4275;

int main() {
    double cuteResult = 0.0;
    cuteResult = windChill(30.0, 0);
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

void printoutRows() {
    string xAxis = "Temperature (F)";
    string yAxis = "Windspeed (mph)";
    int currentTemp = 0;
    int startTemp = 40;
    int endTemp = 0;
    int n = 40/5;

    currentTemp = startTemp;
    //print out x-axis
    cout << setw(yAxis.length() + 1) << "wanna repeatChar(' ') here "<< xAxis << "/n";
    //print out y-axis and temp values from 40 to 0.
    cout << setw(yAxis.length() + 1) << yAxis;
    //need a for loop here to from temp 40 to 0 (in increments of 5.)

    for(int i = 0; i < n; i++) {
        cout << setw(3) << currentTemp << "|";
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

