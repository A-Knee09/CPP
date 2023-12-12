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

class Binary
{
public:
    int Search(int *arr, int n, int key)
    {

        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] < key)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
        return -1;
    }
};

int main()
{
    array *a = new array;
    Binary *b = new Binary;
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    a->Inp(arr, n);
    cout << "Enter the key: ";
    cin >> key;
    int index = b->Search(arr, n, key);
    cout << "key found at position: " << index + 1 << endl;
}
