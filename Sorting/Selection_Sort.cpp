//Written by Anirudh Saksena
#include <iostream>
using namespace std;

class sort
{
private:
int i;
int j;
int min_idx;

public:
// Function for taking input in array
    void Inp(int arr[], int n)
    {
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
// Function for displaying array output
    void Out(int arr[], int n)
    {
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
// Function for Selection Sort
    void Selec_Sort(int arr[], int n)
    {
        for (i = 0; i < n - 1; i++)
        {
            // assuming initial postion is the smallest
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[min_idx] > arr[j])
                {
                    //assign new smallest position if comparision is true
                    min_idx = j;
                }
            }
            // swap elements 
            if (min_idx != i)
            {
                int temp = arr[min_idx];
                arr[min_idx] = arr[i];
                arr[i] = temp;
            }
        }
    }
};

int main()
{
    sort s;
    int arr[100];
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout << "Enter the array: ";
    s.Inp(arr , n);
    s.Out(arr,n);
    cout<<endl;
    cout << "The sorted array is: ";
    s.Selec_Sort(arr, n);
    s.Out(arr , n);
}
