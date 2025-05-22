/*The text in the image is in Lithuanian. Here’s the translation:

Leap Year

In the Gregorian calendar, leap years are calculated as follows:

If the year is divisible by 4, it is a leap year. However, the last year of a century (divisible by 100) is not a
    leap year unless it is divisible by 400.

Create a program where the user inputs a year, and it calculates whether the year is a leap year or not.
If the year is not divisible by 4, it is not a leap year.
If the year is divisible by 4, it is a leap year.
If the year is divisible by 100 and by 400, it is a leap year.*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int x;
    bool ly;

    cout << "Enter a year ";
    cin >> x;

       ly = (x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0));

    cout << "Is " << x << " a leap year?:" << boolalpha << ly << endl;
    cout << endl;
}
