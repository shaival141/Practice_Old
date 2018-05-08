#include<iostream>
#include <algorithm>
using namespace std;
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%3d ", arr[i]);
    printf("\n");
}

void reverseArray(int arr[],int low,int high)
{
    while(low<high)
    {
        swap(&arr[low++],&arr[high--]);
    }
}

void rearrangeWithO1Space(int arr[], int n)
{
    int minIdx =0;
    int maxIdx = n-1;
    int maxElement = arr[n-1] + 1;
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            arr[i]+=arr[minIdx++]%maxElement * maxElement;
        }
        else
        {
            arr[i]+=arr[maxIdx--]%maxElement * maxElement;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i]/=maxElement;
    }
}

void rearrange(int arr[], int n)
{
    int temp[n];
    bool isLarge = true;
    int small = 0;
    int large = n-1;
    for(int i=0;i<n;i++)
    {
        if(isLarge)
        {
            temp[i]=arr[large--];
        }
        else
        {
            temp[i]=arr[small++];
        }
        isLarge=!isLarge;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
}
 
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Arrayn";
    printArray(arr, n);
    rearrangeWithO1Space(arr, n);
    cout << "nModified Arrayn";
    printArray(arr,n);
    return 0;
}
