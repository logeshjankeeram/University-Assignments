// Write a program to determine which value is bigger: e^pi or pi^e

#include <iostream>
#include <cmath>
using namespace std;

int main()

{
    bool b;

    b = pow(exp(1), M_PI) > pow(M_PI, exp(1));

    cout << "Is e^pi bigger than pi^e ? " << b << endl;
    return 0;
}