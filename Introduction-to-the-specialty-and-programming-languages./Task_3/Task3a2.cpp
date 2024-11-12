/*Write a program to solve the quadratic equation:
ax2 + bx + c = 0.
Initial data: equation coefficients a, b, c. Data is entered using the keyboard.*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double a, b, c, x1, x2;

    cout << "enter value for a:";
    cin >> a;

    cout << "enter value for b:";
    cin >> b;

    cout << "enter value for c:";
    cin >> c;

    if (((pow(b, 2)) - (4 * a * c)) < 0)
    {

        cout << "No roots ";
    }
    else
    {
        x1 = (-b + sqrt((pow(b, 2)) - (4 * a * c))) / (2 * a);
        x2 = (-b - sqrt((pow(b, 2)) - (4 * a * c))) / (2 * a);

        cout << "roots of this equation are: " << x1 << " and " << x2 << endl;
    }

    return 0;
}