#include <iostream>

using namespace std;

template <class T>

T sum(T *a, T *b)
{

    T f = 5;

    return (*a + *b) - f;
}

int main()
{

    int i = 50, j = 25;
    double x = 10.2, y = 2.4;

    cout << sum(&i, &j) << "  " << sum(&x, &y);

    return 0;
}