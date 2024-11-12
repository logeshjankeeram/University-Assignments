/*Write a C++ program that determines whether a triangle can be formed from the given segments.
Initial data: lengths of three segments a, b, c. Data is entered using the keyboard.*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, x, c;
    cout << "Enter length a: ";
    cin >> a;
    cout << "Enter length b: ";
    cin >> b;
    cout << "Enter length c: ";
    cin >> c;

    x = max(a, max(b, c));

    if (x >= (0.5 * (a + b + c)))
    {
        cout << "No triangle can be formed";
    }
    else
    {
        cout << "triangle can be formed" << endl;
    }

    return 0;
}
