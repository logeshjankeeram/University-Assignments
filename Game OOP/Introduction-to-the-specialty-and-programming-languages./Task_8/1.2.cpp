#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;

    double distanceFromOrigin() const
    {
        return sqrt(x * x + y * y);
    }
};

int main()
{
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    Point points[100];

    for (int i = 0; i < n; ++i)
    {
        inputFile >> points[i].x >> points[i].y;
    }
    inputFile.close();

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (points[i].distanceFromOrigin() > points[j].distanceFromOrigin())
            {

                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }

    cout << "Sorted by distance from the origin:" << endl;
    for (int i = 0; i < n; ++i)
    {
        double distance = points[i].distanceFromOrigin();
        cout << "(" << points[i].x << ", " << points[i].y << ") ~ Distance is " << distance << endl;
    }

    return 0;
}
