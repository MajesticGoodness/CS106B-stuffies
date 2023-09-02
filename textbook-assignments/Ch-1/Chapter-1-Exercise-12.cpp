#include <iostream>
#include <console.h>
#include <cmath>

using namespace std;

double calcHeightRect (double r, double x);
double calcIntervalWidth(double r, double n);
double calcArea(double width, double height);
double getApproximationMagnitude();
double computeAreaApproximation(double width, double r);

int main() {
    double r = 2;
    double n = 0;
    double width = 0;
    n = getApproximationMagnitude();
    width = calcIntervalWidth(r, n);
    computeAreaApproximation(width, r);
    return 0;
}

double calcHeightRect(double r, double x) {
    double height = 0;
    double formula = ((r * r) - (x * x));
    height = sqrt(formula);
    return height;
}

double calcdoubleervalWidth(double r, double n) {
    double width = 0;
    width = r / n;
    return width;
}

double calcArea(double width, double height) {
    double area = 0;
    area = width * height;
    return area;
}

double getApproximationMagnitude() {
    double n = 0;
    cout << "Please enter the number of rectangles to be used for the approximation: ";
    cin >> n;
    return n;
}

double computeAreaApproximation(double width, double r) {
    double summedArea = 0;

    for(double i = 0; i <= r; i += width) {
        double height = 0;
        height = calcHeightRect(r, i);
        summedArea += calcArea(width, height);
    }
    return summedArea;
}
