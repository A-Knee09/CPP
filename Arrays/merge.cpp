#include<iostream>
using namespace std;

int main()
{
    int a[2] , b[3] ,c[2+3];
    cout<<"Enter the elements of the first array"<<endl;
    for (int i = 0; i < 2; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the elements of the second array"<<endl;
    for (int j = 0; j < 3; j++)
    {
        cin>>b[j];
    }
    for (int q = 0; q <= 2; q++)
    {
        c[q] = a[q];
    }
    for ( int w = 0; w <= 3; w++)
    {
        c[w+2] = b[w];
    }
    cout<<"Merged array is: ";
    for (int t = 0; t < 5; t++)
    {
        cout<<c[t]<<" ";
    }    
}