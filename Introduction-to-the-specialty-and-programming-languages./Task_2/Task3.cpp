// task 3
/*
thought process:
(0<= |x| <= 1) and (0 <= y <= 1)  and x>=|y|-- this is wronggg

distance from origin should be less than 1 and |x|+|y| >=1 for eg, (0.25+0.75)


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

    if (((fabs(x) + fabs(y) >= 1) && (sqrt(pow(x, 2) + pow(y, 2)) <= 1)))
    {
        cout << "Coordinate is found in shaded area" << endl;
    }
    else
    {
        cout << "Coordinate is not found in shaded area" << endl;
    }

    return 0;
}