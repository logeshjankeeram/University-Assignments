#include <iostream>
#include <cmath>
using namespace std;

long long int Factorial(int n) // Changed to long long int for larger values
{
    if (n == 0)
        return 1;
    else
        return Factorial(n - 1) * n;
}

int main() // Changed return type to int
{
    int m;
    cout << "Enter an integer: ";
    cin >> m;

    if (m < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
    }
    else
    {
        cout << "Factorial(" << m << ") = " << Factorial(m) << endl;
    }

    return 0;
}