#include <iostream>
using namespace std;

int c(int m, int n) {
    if (m==0 || m==n){
        return 1;
    }
    return c(m, n-1) + c(m-1, n-1);
}

int main() {
    int num1, num2;
    cout << "Enter the 2 values: ";
    cin >> num1>>num2;

    if (num1 < 0 || num2 < 0 || num1 > num2) {
        cout << "undefined" << endl;
        return 1;
    }
    cout << "the output is " << c(num1, num2) << endl;

    return 0;
}