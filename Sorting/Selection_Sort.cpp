#include <iostream>
using namespace std;

class Array
{
public:
    void Inp(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void Out(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Selection
{
public:
    int i;
    int j;
    int min_idx;
    int temp;
    void Sort(int *arr, int n)
    {
        for (i = 0; i < n - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }
            if (min_idx != i)
            {
                temp = arr[min_idx];
                arr[min_idx] = arr[i];
                arr[i] = temp;
            }
        }
    }
};

int main()
{
    Array *a = new Array;
    Selection *s = new Selection;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    a->Inp(arr, n);
    cout << "Orignal Array is : ";
    a->Out(arr, n);
    cout << "Sorted Array is: ";
    s->Sort(arr, n);
    a->Out(arr, n);
}
