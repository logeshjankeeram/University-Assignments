#include <iostream>
#include <cmath>
using namespace std;

bool Leap_year_Gregorian(int y)
{
    return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int main()
{
    int day1, month1, year1, day2, month2, year2, i, y, count = 0;
    int total1 = 0, total2 = 0, total3 = 0;

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

    for (int m = 1; m < month2; m++)
    {
        if (m == 2)
        {
            total2 += (Leap_year_Gregorian(year2) ? 29 : 28);
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            total2 += 30;
        }
        else
        {
            total2 += 31;
        }
    }
    total2 += day2;

    for (int m = 1; m < month1; m++)
    {
        if (m == 2)
        {
            total1 += (Leap_year_Gregorian(year1) ? 29 : 28);
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            total1 += 30;
        }
        else
        {
            total1 += 31;
        }
    }
    total1 += day1;

    if (year1 == year2)
    {
        total3 = total2 - total1;
    }

    total1 = (Leap_year_Gregorian(year1)) ? (366 - total1) : (365 - total1);

    if (year1 + 1 == year2)
    {
        total3 = total2 + total1;
    }

    else if (year1 + 2 == year2)
    {
        total3 = total2 + total1 + (Leap_year_Gregorian(year1 + 1) ? 366 : 365);
    }

    else if (year1 + 2 < year2)
    {
        y = (year2 - year1) - 1;

        for (i = year1 + 1; i < year2; i++)
        {
            if (Leap_year_Gregorian(i))
                count += 1;
        }

        total3 = ((y - count) * 365) + (count * 366) + total1 + total2;
    }

    cout << "Total days between the two dates: " << total3 << endl;
    return 0;
}