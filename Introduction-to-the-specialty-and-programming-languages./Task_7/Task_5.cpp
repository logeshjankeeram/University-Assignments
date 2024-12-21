#include <iostream>
using namespace std;

int sumtotal()
{
    int x;
    cin >> x;
    if (x < 0)
    {
        return 0;
    }
    return x + sumtotal();
}
int main()
{
    cout << "enter the values - " << endl;
    int total = sumtotal();
    cout << "the sum of an ouput - " << total << endl;

    return 0;
}