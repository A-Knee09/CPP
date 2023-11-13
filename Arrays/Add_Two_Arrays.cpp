#include<iostream>
using namespace std;

void Inp(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
}


void Out(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }   
}

int sum(int arr[] , int arr2[] , int res[] , int size)
{
    for (int i = 0; i < size; i++)
    {
        res[i] = arr[i]+arr2[i];
    }
    
}

int main()
{
    int arr[100] , arr2[100] , res[100];
    int size1, size2 , size3;   
    cout<<"Enter the size of the array: ";
    cin>>size1;
    cout<<"Enter the elements of the array: ";
    Inp(arr , size1);
    cout<<"Enter the size of the array: ";
    cin>>size2;
    cout<<"Enter the elements of the array: ";
    Inp(arr2 , size2);
    if (size1> size2)
    {
        size3 = size1;
    }
    else if(size2>size1)
    {
        size3=size2;
    }
    else
    {
        size3=size1;
    }   
    sum(arr , arr2 , res, size3);
    Out(res , size3);
    
}