#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

void cocktailShakerSort(vector<int> &arr)
{
    bool swapped = true;
    int start = 0, end = arr.size() - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
                printArray(arr);
            }
        }
        if (!swapped)
            break;
        swapped = false;
        end--;

        for (int i = end - 1; i >= start; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
                printArray(arr);
            }
        }
        start++;
    }
}

int main()
{
    vector<int> arr = {29, 10, 14, 37, 13};
    cout << "Original array: ";
    printArray(arr);

    cout << "\nCocktail Shaker Sort steps:\n";
    cocktailShakerSort(arr);

    cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}