#include <iostream>
using namespace std;

bool isLeapYear(int year, bool gregorian)
{
    return gregorian ? ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) : (year % 4 == 0);
}

int daysInYear(int startYear, int endYear)
{
    int days = 0;
    for (int y = startYear; y <= endYear; y++)
    {
        bool gregorian = y > 1582 || (y == 1582 && 10 > 10);
        days += isLeapYear(y, gregorian) ? 366 : 365;
    }
    return days;
}

int daysInMonths(int year, int month, int day)
{
    int days = day;
    bool gregorian = year > 1582 || (year == 1582 && month > 10);

    for (int m = 1; m < month; m++)
    {
        if (m == 2)
            days += isLeapYear(year, gregorian) ? 29 : 28;
        else if (m == 4 || m == 6 || m == 9 || m == 11)
            days += 30;
        else
            days += 31;
    }
    return days;
}

int main()
{
    int day1, month1, year1, day2, month2, year2;
    int totalDays = 0;

    cout << "From which day? ";
    cin >> day1;

    cout << "From which month? ";
    cin >> month1;

    cout << "From which year? ";
    cin >> year1;

    cout << "Till which day? ";
    cin >> day2;

    cout << "Till which month? ";
    cin >> month2;

    cout << "Till which year? ";
    cin >> year2;

    if (year1 == year2)
    {
        totalDays = daysInMonths(year2, month2, day2) - daysInMonths(year1, month1, day1);
    }
    else if (year1 < year2)
    {
        totalDays = daysInYear(year1 + 1, year2 - 1) + daysInMonths(year2, month2, day2) + (365 - daysInMonths(year1, month1, day1));
    }
    else
    {
        totalDays = daysInYear(year2 + 1, year1 - 1) + (365 - daysInMonths(year2, month2, day2)) + daysInMonths(year1, month1, day1);
    }

    cout << "Total days between the two dates: " << abs(totalDays) << endl;
    return 0;
}