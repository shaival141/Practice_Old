// C++ program to implement three way partitioning
// around a given range.
#include<iostream>
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
        printf("%4d ", arr[i]);
    printf("\n");
}

// Partitions arr[0..n-1] around [lowVal..highVal]
void threeWayPartition(int arr[], int n,int lowVal, int highVal)
{
    int start = 0,end = n-1;
    for(int i=0;i<end;)
    {
        if(arr[i]<lowVal)
        {
            swap(&arr[i++],&arr[start++]);
        }
        else if(arr[i]>highVal)
        {
            swap(&arr[end--],&arr[i]);
        }
        else
        {
            i++;
        }
    }
}
 
// Driver code
int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87,
                98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    threeWayPartition(arr, n, 10, 20);
 
    cout << "Modified array \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
