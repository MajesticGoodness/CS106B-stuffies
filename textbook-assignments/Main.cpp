#include <iostream>
#include <console.h>
#include <cmath>

using namespace std;

enum Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int daysInMonth(Month month, int year);
string monthToString(Month month);
bool isLeapYear(int year);

int daysInMonth(Month month, int year) {
    switch (month) {
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
        return 30;
    case FEBRUARY:
        return (isLeapYear(year)) ? 29 : 28;
    default:
        return 31;
    }
}

bool isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0))
            || (year % 400 == 0);
}

string monthToString(Month month) {
    switch (month) {
    case JANUARY:
        return "January";
        break;
    case FEBRUARY:
        return "February";
        break;
    case MARCH:
        return "March";
        break;
    case APRIL:
        return "April";
        break;
    case MAY:
        return "May";
        break;
    case JUNE:
        return "June";
        break;
    case JULY:
        return "July";
        break;
    case AUGUST:
        return "August";
        break;
    case SEPTEMBER:
        return "September";
        break;
    case OCTOBER:
        return "October";
        break;
    case NOVEMBER:
        return "November";
        break;
    case DECEMBER:
        return "December";
        break;
    default:
        return "Invalid month";
    }
}


int main() {
    return 0;
}
