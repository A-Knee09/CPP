// Given an arr of length N and an integer K, find the total number of occurrences of K in arr.
#include <iostream>
using namespace std;
void Input(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void PrintArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int FirstOcc(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int LastOcc(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int len, arr[1000];
    cout << "Enter the lenght of the array: ";
    cin >> len;
    Input(arr, len);
    cout << "The array is: ";
    PrintArr(arr, len);
    cout << endl;
    int key;
    cout << "Enter the key: ";
    cin >> key;
    int first = FirstOcc(arr, len, key);
    cout << "First occurrence of " << key << " is at index " << first << endl;
    int last = LastOcc(arr, len, key);
    cout << "Last occurrence of " << key << " is at index " << last;
    cout << endl;
    int total = (last - first) + 1;
    cout << "The total number of " << key << " is: " << total;
}