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

class reverse
{
public:
    void rev(int *arr, int n)
    {
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }
};

int main()
{
    array *a = new array;
    reverse *r = new reverse;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    a->Inp(arr, n);
    cout << "Orignal array: ";
    a->Out(arr, n);
    r->rev(arr, n);
    cout << "Reversed array: ";
    a->Out(arr, n);
}
