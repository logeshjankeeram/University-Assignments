#include <iostream>
using namespace std;
#include <cmath>

int main()
{

    double F, R, m1, m2;

    cout << "Enter the value of R: ";
    cin >> R;

    cout << "Enter the value of m1: ";
    cin >> m1;

    cout << "Enter the value of m2: ";
    cin >> m2;

    F = (6.673 * (pow(10, -8)) * (m1) * (m2)) / (pow(R, 2));

    cout << "The value of F is: " << F << endl;

    return 0;
}