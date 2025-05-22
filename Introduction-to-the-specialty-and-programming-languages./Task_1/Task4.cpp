// Calculate a distance between the two points with coordinates (x1, y1) and (x2, y2).

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double x1, x2, y1, y2, d;

    cout << "enter x1: ";
    cin >> x1;

    cout << "enter x2: ";
    cin >> x2;

    cout << "enter y1: ";
    cin >> y1;

    cout << "enter y2: ";
    cin >> y2;

    d = sqrt(pow((x2 - x1), 2) + (pow((y2 - y1), 2)));

    cout << "Distance is: " << d << endl;

    return 0;
}