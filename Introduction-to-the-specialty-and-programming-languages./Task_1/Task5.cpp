// Calculate sin(30 ) and determine that the result is equal to --- 0.5

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double degree = 30.0;
    double rad = degree * (M_PI / 180);

    double sine = sin(rad);

    cout << sine << " is equal to 0.5" << endl;
    return 0;
}