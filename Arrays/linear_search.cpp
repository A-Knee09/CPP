#include <iostream>
using namespace std;

void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

bool isPresent(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int size;
    int arr[100];
    int key;
    cout << "Enter the size of the array: ";
    cin >> size;
    printarray(arr, size);
    cout << "Enter the key: ";
    cin >> key;

    bool found = isPresent(arr, 5, key);

    if (found)
    {
        cout << "Present.";
    }
    else
    {
        cout << "Not present.";
    }
}