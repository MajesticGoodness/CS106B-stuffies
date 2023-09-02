/*
 * File: calendar.h
 * _________________
 * This interface exports an enumerated type called MONTH as well as a few functions
 * for working with months of the calendar.
 */

#ifndef CALENDAR_H
#define CALENDAR_H

/*
 * Type: Month
 * ___________
 * This type represents the 12 months of a calendar year.
 */

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

/*
 * Function: daysInMonth
 * Usage: int days = daysInMonth(Month, int);
 * _________________________________________
 * Returns the number of days in a month, while also accounting leap years.
 */

int daysInMonth(Month month, int year);

/*
 * Function: monthToString
 * Usage: string month = monthToString(Month);
 * ------------------------------------------
 * Returns the name of a month as a string.
 */

std::string monthToString(Month month);

/*
 * Function: isLeapYear
 * Usage: if (isLeapYear) {
 *          statements;
 *        }
 * ____________________
 * Returns true if the input year is a leap year. Returns false otherwise.
 */

bool isLeapYear(int year);


#endif // CALENDAR_H
