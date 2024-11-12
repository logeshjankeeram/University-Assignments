#include <iostream>
using namespace std;
#include <cmath>

int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    double x, y;

    cout << "enter values of x: ";
    cin >> x;

    y = 1 + x + (pow(x, 2) / factorial(2)) + (pow(x, 3) / factorial(3)) + (pow(x, 4) / factorial(4));

    cout << "The value of y is: " << y << endl;

    return 0;
}