#include<iostream>
using namespace std;

int sum(int arr[],int n)
{
    int sum = 0;
    for(int i=0 ; i<n ; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main()
{
    int size;
    cout<<"Enter the number of elements of array: ";
    cin>>size;
    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"The sum is: "<<sum(arr , size)<<endl;
}