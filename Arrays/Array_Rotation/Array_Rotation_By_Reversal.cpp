#include <cstdio>
using namespace std;

void reverseArray(int arr[],int i,int j)
{
    while(i<j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;j--;
    }
}
void rotateArray(int arr[], int n, int d)
{
    reverseArray(arr,0,d-1);
    reverseArray(arr,d,n-1);
    reverseArray(arr,0,n-1);
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