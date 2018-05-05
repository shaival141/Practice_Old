#include <cstdio>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findPivot(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid]>arr[mid+1])
        return mid;
        if(arr[low]>arr[mid])
        return findPivot(arr,0,mid-1);
        return findPivot(arr,mid+1,high);
    }
    return low;
}

int binarySearch(int arr[],int low,int high,int key)
{
    if(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            return binarySearch(arr,low,mid-1,key);
        }
        return  binarySearch(arr,mid+1,high,key);
    }
    return -1;
}

int pivotedBinarySearch(int arr[],int n,int key)
{
    int p  = findPivot(arr,0,n-1);
    if(key > arr[p])
    {
        return -1;
    }
    else if(key<arr[0])
    {
        return binarySearch(arr,p+1,n-1,key);
    }
    else
    {
        return binarySearch(arr,0,p,key);
    }
}

int main()
{
    int arr[] = {6, 7, 8, 9, 10, 11, 13,1,2,3,4};
    int key = 12;
    int n = sizeof(arr) / sizeof(int);
    printf("%d\n",pivotedBinarySearch(arr,n,key));
    return 0;
}