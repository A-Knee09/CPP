// Create an array and find the maximum and the minimum element in it.
#include <iostream>
#include <limits.h>
using namespace std;

int getMax(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        // if (arr[i] > max)
        // {
        //     max = arr[i];
        // }
    }

    return maxi;
}

int getMin(int arr[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}
int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum value is: " << getMax(arr, size) << endl;
    cout << "Minimum value is: " << getMin(arr, size) << endl;
    return 0;
}