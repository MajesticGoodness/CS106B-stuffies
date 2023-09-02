#include <iostream>
#include <iomanip>
#include "console.h"
using namespace std;

void welcomeMessage();
void promptMessage();
double getCelsiusInput();
double celsiusToFahrenheit(double celsius);
void displayFahrenheit(double fahrenheit);





int main() {
    double celsius    = 0;
    double fahrenheit = 0;
    welcomeMessage();
    promptMessage();
    celsius    = getCelsiusInput();
    fahrenheit = celsiusToFahrenheit(celsius);
    displayFahrenheit(fahrenheit);

  return 0;
}

void welcomeMessage() {
    string welcomeMessage = "Welcome to the Celsius to Fahrenhiet conversion tool!";
    cout << welcomeMessage << '\n' ;
}

void promptMessage() {
    string promptMessage = "Please enter the degrees in Celsius to be converted: ";
    cout << promptMessage << '\n' ;
}

double getCelsiusInput() {
    double celsius = 0;
    cin >> celsius;
    return celsius;
}

double celsiusToFahrenheit(double celsius) {
    double fahrenheitNum = celsius * (9.0 / 5.0) + 32;
    return fahrenheitNum;
}

void displayFahrenheit(double fahrenheit) {
    string fahrenheitMessage = "degrees Fahrenheit";
    cout << setprecision(3) << fahrenheit << " " << fahrenheitMessage;
}



