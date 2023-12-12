#include <iostream>
using namespace std;

class array
{
public:
    void Inp(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << endl;
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

class Bubble
{
public:
    int i, j, temp;
    void sort(int *arr, int n)
    {
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    array *a = new array;
    Bubble *s = new Bubble;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    a->Inp(arr, n);
    cout << "Orignal array: ";
    a->Out(arr, n);
    cout << "Sorted array: ";
    s->sort(arr, n);
    a->Out(arr, n);
}
