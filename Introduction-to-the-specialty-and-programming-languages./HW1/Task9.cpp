// Calculate a sum of digits of the triple-digit number (for example: 286 = 16).

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, hundredth, tens, unit, sum;
    cout << "Enter a number: ";
    cin >> x;
    hundredth = x / 100;
    tens = (x - (hundredth * 100)) / 10;
    unit = (x - ((hundredth * 100) + (tens * 10)));

    sum = hundredth + tens + unit;

    cout << "sum is: " << sum << endl;

    return 0;
}