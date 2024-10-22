/*Write a program to determine whether a point with coordinates (x, y) falls within the shaded
area of the figure below. Point coordinates are entered using the keyboard.

Thought process:

i think this is easier than task one but similar

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y;

    cout << "Enter x coordinate: ";
    cin >> x;

    cout << "Enter y coordinate: ";
    cin >> y;

    if (((fabs(x) <= 1 && fabs(x) >= 0) && (y <= 1 && y >= -1)))
    {
        cout << "Coordinate is found in shaded area" << endl;
    }
    else
    {
        cout << "Coordinate is not found in shaded area" << endl;
    }

    return 0;
}