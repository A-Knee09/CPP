#include<iostream>
using namespace std;

void InpArr(int arr[] , int size)
{
    for(int i = 0; i<size ; i++)
    {
        cin>>arr[i];
    }
}

void PrintArr(int arr[] , int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;   
}

void swapAlt(int arr[] , int n)
{
    for(int i = 0; i<n ; i+=2)
    {
        if(i+1<n)
        {
            swap(arr[i] , arr[i+1]);
        }
    }
}
int main()
{
    int len , arr[100];
    cout<<"Enter the length of the array: ";
    cin>>len;
    InpArr(arr , len);
    cout<<"The array is: ";
    PrintArr(arr , len);
    swapAlt(arr , len);
    cout<<"Swapped array is: ";
    PrintArr(arr , len);

}