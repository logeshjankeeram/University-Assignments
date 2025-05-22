#include <iostream>

using namespace std;

int main()
{
    int x = 5;
    int y = 10;

    int temp = x;
    x = y;
    y = temp;

    cout << "x is: " << x << " and y is " << y << endl;

    int x = 5;
    int y = 10;

    x = x + y;
    y = x - y;
    x = x - y;

    cout << "x is: " << x << " and y is " << y << endl;

    return 0;
}