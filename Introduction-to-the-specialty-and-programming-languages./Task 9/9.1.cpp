#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &arr)
{
    for (const int &num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

void binaryInsertionSort(vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int x = arr[i];
        int left = 0, right = i;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        for (size_t j = i; j > left; j--)
        {
            arr[j] = arr[j - 1];
        }

        arr[left] = x;

        cout << "Step " << i << ": ";
        printArray(arr);
    }
}

int main()
{

    vector<int> arr = {29, 10, 14, 37, 13};
    cout << "Original array: ";
    printArray(arr);

    cout << "\nBinary Insertion Sort steps:\n";
    binaryInsertionSort(arr);

    cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}