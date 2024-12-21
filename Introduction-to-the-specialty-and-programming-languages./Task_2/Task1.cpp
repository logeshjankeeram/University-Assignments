// Task 1.
// Write a program to determine whether a point with coordinates (x, y) falls within the shaded
// area of the figure below. Point coordinates are entered using the keyboard.

// thought process:
/* coordinates of triangle: (-1,1) to (1,1) to (0,0)

For positive side

x has to be less than 1 and y less than 1
since gradient is 1, so if y=x or y>x then it would fall in the positive shaded area.

for negative side: -1 <= x <= 1 and 0 <= y <= 1
y=>-(x)


general rules:

(0<= |x| <= 1) and (0 <= y <= 1)  and y>=|x|

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

    if (((fabs(x) <= 1 && fabs(x) >= 0) && (y <= 1 && y >= 0)) && (fabs(x) <= y))
    {
        cout << "Coordinate is found in shaded area" << endl;
    }
    else
    {
        cout << "Coordinate is not found in shaded area" << endl;
    }

    return 0;
}
