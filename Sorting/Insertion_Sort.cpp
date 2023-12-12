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

class Insertion
{
public:
    void sort(int *arr, int n)
    {
        int i, j, temp;

        for (i = 1; i < n; i++)
        {
            temp = arr[i];
            j = i - 1;
            while (j >= 0 && temp <= arr[j])
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
};

int main()
{
    array *a = new array;
    Insertion *s = new Insertion;
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
