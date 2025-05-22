#include <iostream>
using namespace std;

int fib(int x) {
    if (x==1 || x==2) { 
        return 1;
    }
    return fib(x - 1) + fib(x - 2);
}

int main() {
    int num;
    cout << "Enter the value: ";
    cin >> num;

    if (num <= 0) { 
        cout << "Not defined" << endl;
        return 1; 
    }

    cout << "Fibonacci number " << num << " is " << fib(num) << endl;

    return 0;
}
