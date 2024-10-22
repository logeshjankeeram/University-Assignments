/*Describe two integer variables x and y. Enter their values from the keyboard.
Then, assign true to a boolean (logical) variable B, if x = y, otherwise assign B = false.*/

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    bool B;

    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Enter the value of y: ";
    cin >> y;

    B = (x == y);

    if (B)
    {
        cout << "x and y are equal." << endl;
    }
    else
    {
        cout << "x and y are not equal." << endl;
    }

    return 0;
}