#include <iostream>
#include <cmath>
using namespace std;
double Power(double f, int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 1 / Power(f, abs(n));
    else
        return f * Power(f, (n - 1));
}
int main()
{
    int m;
    double x;
    cout << "Please, enter a real number and an integer: ";
    cin >> x >> m;
    cout << "\nPower(" << x << "," << m << ") = " << Power(x, m) << endl;
    return 0;
}