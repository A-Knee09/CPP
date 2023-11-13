// All sorting alogrithms
#include <iostream>
using namespace std;
class sort
{
public:
    void Inp(int arr[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    void Out(int arr[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void selection(int arr[], int n)
    {
        int i , j , min_idx;
        for (i = 0; i < n - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[min_idx] > arr[j])
                {
                    min_idx = j;
                }
            }

            if (min_idx != i)
            {
                int temp = arr[min_idx];
                arr[min_idx] = arr[i];
                arr[i] = temp;
            }
        }
    }

    void bubble(int arr[], int n)
    {
        int i , j, temp;
        for (i = 0; i < n - 1; i++)
        {
            int swapped = true;
            for (j = 0; j < n - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
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

    void Ins(int arr[], int n)
    {
        int i , j , temp;
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
    int arr[100];
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the array: ";
    s.Inp(arr, n);
    s.Out(arr, n);
    cout << endl;
    cout << "The sorted array is (Selection): ";
    s.selection(arr, n);
    s.Out(arr, n);
    cout<<endl;
    cout << "The sorted array is (bubble): ";
    s.bubble(arr, n);
    s.Out(arr, n);
    cout<<endl;
    cout << "The sorted array is (Insertion): ";
    s.Ins(arr, n);
    s.Out(arr, n);
}