#include<iostream>
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
int Unique(int *arr , int size)
{
    int ans = 0;
    for(int i = 0; i<size ; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
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
    cout<<"Unique element is: ";
    Unique(arr , len);
}