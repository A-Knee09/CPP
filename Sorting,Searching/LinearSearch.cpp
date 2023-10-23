#include <iostream>
using namespace std;

class Search
{
public:
    void Inp(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    void Out(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    bool LinearSearch(int arr[], int n, int key)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                return 1;
            }
        }
        return 0;
    }
};

int main()
{
    Search *s = new Search;
    int arr[100], n, key;

    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    s->Inp(arr, n);
    cout << "Enter the key: ";
    cin >> key;
    bool isFound = s->LinearSearch(arr, n, key);
    if (isFound)
    {
        cout << "Key found!";
    }
    else
    {
        cout << "Not found.";
    }
}