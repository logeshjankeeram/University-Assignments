// Enter the value of integer a variable, then print this number matrix on the screen
/*
a
a3 a6
a6 a3 a
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double a, a3, a6;
    cout << "Enter any integer value: ";
    cin >> a;

    a3 = pow(a, 3);
    a6 = a3 * a3;

    cout << a << endl;
    cout << a3 << " " << a6 << endl;
    cout << a6 << " " << a3 << " " << a << endl;

    return 0;
}