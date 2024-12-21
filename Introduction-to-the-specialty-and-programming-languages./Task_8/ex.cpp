#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the input file." << endl;
        return 1;
    }

    int n;
    inputFile >> n; // Read the number of points

    int x[100], y[100];        // Arrays to store x and y coordinates (assuming max 100 points)
    double distances[100];     // Array to store distances
    double maxDistance = -1.0; // Variable to track the maximum distance
    int furthestIndex = -1;    // Index of the furthest point

    // Read points and calculate distances
    for (int i = 0; i < n; ++i)
    {
        inputFile >> x[i] >> y[i];
        distances[i] = sqrt(x[i] * x[i] + y[i] * y[i]);

        // Update the furthest point if this distance is greater
        if (distances[i] > maxDistance)
        {
            maxDistance = distances[i];
            furthestIndex = i;
        }
    }

    inputFile.close();

    // Write the furthest point and its distance to the output file
    if (furthestIndex != -1)
    {
        outputFile << "Furthest Point: (" << x[furthestIndex] << ", " << y[furthestIndex] << ")\n";
        outputFile << "Distance from Origin: " << maxDistance << "\n";
    }
    outputFile.close();

    // Sort points manually by distance using Bubble Sort
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (distances[j] > distances[j + 1])
            {
                // Swap distances
                double tempDist = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = tempDist;

                // Swap coordinates
                int tempX = x[j];
                int tempY = y[j];
                x[j] = x[j + 1];
                y[j] = y[j + 1];
                x[j + 1] = tempX;
                y[j + 1] = tempY;
            }
        }
    }

    // Display sorted points
    cout << "Points sorted by distance from origin:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "(" << x[i] << ", " << y[i] << ") - Distance: " << distances[i] << endl;
    }

    return 0;
}
