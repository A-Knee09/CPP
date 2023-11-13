#include <iostream>
using namespace std;
void InpArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void Printarray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int len;
    int arr[100];
    cout << "Enter the lenght of the array: ";
    cin >> len;
    InpArray(arr, len);
    cout << "The array is: ";
    Printarray(arr, len);

    cout << "Reversed array is: ";
    reverse(arr, len);
    Printarray(arr, len);
    cin.get();
}
