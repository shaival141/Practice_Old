#include <cstdio>

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

void rearrange(int arr[], int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1 || arr[i]==i)
        {
            continue;
        }
        else
        {
            int j = arr[i];
            arr[i]=-1;
            while(j>=0 && arr[j]!=j)
            {
                temp = arr[j];
                arr[j]=j;
                j=temp;
            }
        }
    }
}

// Driver program to test above functions
int main()
{
    int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
