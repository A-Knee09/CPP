#include <iostream>
using namespace std;
// Function to find duplicate values in an array
void findDuplicates(int arr[], int size)
{
    bool found = false;

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[i] == arr[j])
            {
                // If a duplicate is found
                if (!found)
                {
                    cout << "Duplicate values in the array are: ";
                    found = true;
                }
                cout << arr[i] << " ";
                break; // Break the inner loop after finding a duplicate
            }
        }
    }

    if (!found)
    {
        cout << "No duplicate values found in the array.";
    }

    cout << endl;
}

int main()
{
    int arr[] = {4, 2, 3, 2, 7, 8, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}
