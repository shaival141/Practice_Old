#include <cstdio>
using namespace std;


void swap(int arr[],int a,int b,int c)
{
    for(int i=0;i<c;i++)
    {
        int temp = arr[a+i];
        arr[a+i]=arr[b+i];
        arr[b+i]=temp;
    }
}

void rotateArray(int arr[],int n, int d)
{
    if(n-d == d)
    {
        swap(arr,0,n-d,d);
    }
    else if(d<n-d)
    {
        swap(arr,0,n-d,d);
        rotateArray(arr,n-d,d);
    }
    else
    {
        swap(arr,0,d,n-d);
        rotateArray(arr+n-d,d,2*d-n);
    }
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int d = 3;
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    rotateArray(arr, n, d);
    printArray(arr, n);
    return 0;
}