//Find the largest element in the array,Not necessarily sorted but is a mountain.
#include<iostream>
using namespace std;
void Input(int arr[] , int size)
{
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }   
}
void Output(int arr[] , int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int Mountain(int arr[] , int size)
{
    int s = 0 , e = size-1;
    int mid = s+(e-s)/2;
    while(s<e)
    {
        if(arr[mid]<arr[mid+1])
        {
            s = mid+1;
        }
        else
        {
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return arr[s];
}
int main()
{
    int len, arr[1000];
    cout << "Enter the lenght of the array: ";
    cin >> len;
    Input(arr, len);
    cout << "The array is: ";
    Output(arr, len);
    cout << endl;
    int peak = Mountain(arr , len);
    cout<<"The peak element is: "<<peak;
}
