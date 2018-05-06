#include <cstdio>
using namespace std;

int countRotation(int arr[],int n)
{
    int low = 0;
    int high = n-1;
    while(low<high)
    {
       int mid = low+(high-low)/2;
       if(arr[mid]>arr[mid+1])
       {
           return (mid+1);
       }
       else if(arr[mid+1]>arr[high])
       {
           low = mid+1;
       }
       else
       {
           high = mid;
       }
    }
    return low;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    printf("%d\n",countRotation(arr, n));
    return 0;
}