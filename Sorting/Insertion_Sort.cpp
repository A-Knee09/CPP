#include <iostream>
using namespace std;

class sort
{
private:
    int i;
    int j;
    int temp;

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

    void Ins(int arr[], int n)
    {
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
    sort s;
    int arr[100], n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array" << endl;
    s.Inp(arr, n);
    s.Ins(arr, n);
    cout << "Sorted array is: ";
    s.Out(arr, n);
}