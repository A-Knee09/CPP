#include <iostream>
using namespace std;

void Merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int MAI = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[MAI++];
    }
    MAI = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[MAI++];
    }

    int idx1 = 0;
    int idx2 = 0;
    MAI = s;
    while (idx1 < len1 && idx2 < len2)
    {
        if (first[idx1] < second[idx2])
        {
            arr[MAI++] = first[idx1++];
        }
        else
        {
            arr[MAI++] = second[idx2++];
        }
    }

    while (idx1 < len1)
    {
        arr[MAI++] = first[idx1++];
    }
    while (idx2 < len2)
    {
        arr[MAI++] = second[idx2++];
    }
}

void MergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    MergeSort(arr, s, mid);
    MergeSort(arr, mid + 1, e);
    Merge(arr, s, e);
}

int main()
{
    int arr[5] = {2, 7, 1, 0, 4};
    int n = 5;
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}