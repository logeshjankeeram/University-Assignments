/*II. Create a program where the user inputs their height and weight to calculate the body mass index (abbreviated as BMI).


BMI= Weight(kg)/(height (m))^2

    •	BMI < 18.5: Underweight.
    •	18.5 ≤ BMI < 24.99: Normal weight.
    •	25.0 ≤ BMI < 29.99: Overweight.
    •	30.0 ≤ BMI < 34.99: Obesity Class 1.
    •	35.0 ≤ BMI < 39.99: Obesity Class 2.
    •	BMI ≥ 40.0: Obesity Class 3.*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double w, h, BMI;

    cout << "Enter your weight in Kg: ";
    cin >> w;

    cout << "Enter your height cm: ";
    cin >> h;

    h = h / 100;

    BMI = w / pow(h, 2);

    if (BMI < 18.5)
    {
        cout << "Classification: Underweight." << endl;
    }
    else if (BMI < 25)
    {
        cout << "Classification: Normal weight." << endl;
    }
    else if (BMI < 30)
    {
        cout << "Classification: Overweight." << endl;
    }
    else if (BMI < 35)
    {
        cout << "Classification: Obesity Class 1." << endl;
    }
    else if (BMI < 40.0)
    {
        cout << "Classification: Obesity Class 2." << endl;
    }
    else
    {
        cout << "Classification: Obesity Class 3." << endl;
    }

    return 0;
}