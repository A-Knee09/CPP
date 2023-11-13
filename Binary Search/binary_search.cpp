#include<iostream>
using namespace std;

void Input(int arr[] , int size)
{
    for (int i = 0; i < size; i++)
    {
       cin>>arr[i];
    }
    
}
void PrintArr(int arr[] , int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int BinarySearch(int arr[], int size , int key)
{
    int start = 0 ;
    int end = size-1;
    int mid = start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        //To go to the right wala part
        //start update
        if(key>arr[mid])
        {
            start = mid+1;
        }
        //To go to left wala part
        //end update
        else
        {
            end = mid-1;
        }
        //mid update
        mid = start+(end-start)/2;
    }
    return -1;
}
int main()
{
    int len,arr[1000];
    cout<<"Enter the lenght of the array: ";
    cin>>len;
    Input(arr,len);
    cout<<"The array is: ";
    PrintArr(arr , len);
    cout<<endl;
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    int index = BinarySearch(arr , len ,key);
    cout<<"The key "<<key<<" is present at "<<index<<" index";
} 