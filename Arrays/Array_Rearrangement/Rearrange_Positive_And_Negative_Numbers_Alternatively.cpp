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
    int pivot = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (pivot == -1)
            {
                pivot = i;
            }
        }
        else
        {
            if (pivot != -1)
            {
                swap(&arr[pivot], &arr[i]);
                pivot++;
            }
        }
    }
    int j = 1;
    for (int i = pivot; i < n && j < i; j += 2, i++)
    {
        swap(&arr[j], &arr[i]);
    }
}

// Driver program to test above functions
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9, -8, -9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
