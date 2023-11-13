// Written by Anirudh Saksena
#include <iostream>
#include <conio.h>
using namespace std;

class sort
{
private:
    int i;
    int j;

public:
    void Inp(int arr[], int n)
    {
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    void Out(int arr[], int n)
    {
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void bubble(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int swapped = true;
            for (int j = 0; j < n - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (swapped == false)
            {
                break;
            }
        }
    }
};

int main()
{
    sort s;
    int arr[100];
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the array: ";
    s.Inp(arr, n);
    s.Out(arr, n);
    cout << endl;
    cout << "The sorted array is: ";
    s.bubble(arr, n);
    s.Out(arr, n);
}