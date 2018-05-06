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
    //for first
    if (n > 1)
    {
        if (arr[0] < arr[1])
            swap(&arr[0], &arr[1]);
    }
    int i = 2;
    for (; i < n - 1; i += 2)
    {
        if (arr[i - 1] > arr[i])
            swap(&arr[i], &arr[i - 1]);
        if (arr[i + 1] > arr[i])
            swap(&arr[i], &arr[i + 1]);
    }
    //for last
    if (i == n - 1)
    {
        if (arr[i - 1] > arr[i])
            swap(&arr[i], &arr[i - 1]);
    }
}

// Driver program to test above functions
int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
