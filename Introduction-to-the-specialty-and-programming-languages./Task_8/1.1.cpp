#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
};

double calculateDistance(const Point &p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open())
    {
        cerr << "cannot open input file" << endl;
        return 1;
    }
    if (!outputFile.is_open())
    {
        cerr << "cannot open output file" << endl;
        return 1;
    }

    int n;
    inputFile >> n;
    Point furthestPoint = {0, 0};
    double maxDistance = 0.0;

    for (int i = 0; i < n; ++i)
    {
        Point p;
        inputFile >> p.x >> p.y;

        double distance = calculateDistance(p);
        if (distance > maxDistance)
        {
            maxDistance = distance;
            furthestPoint = p;
        }
    }

    inputFile.close();

    outputFile << "Furthermost Point is (" << furthestPoint.x << ", " << furthestPoint.y << ")\n";
    outputFile << "Distance from Origin is  " << maxDistance << endl;

    outputFile.close();
    cout << "Results saved to output.txt" << endl;

    return 0;
}
