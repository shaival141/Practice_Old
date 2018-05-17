#include <iostream>
using namespace std;

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

class MinHeap
{
    int *harr;     // pointer to array of elements in heap
    int heap_size; // size of min heap
  public:
    MinHeap(int a[], int size);
    void MinHeapify(int i);
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int replaceMin(int x);
    int extractMin();
};

MinHeap::MinHeap(int arr[], int size)
{
    heap_size = size;
    harr = arr;
    int i = (size - 1) / 2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin()
{
    int root = harr[0];
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
    }
    return root;
}

int MinHeap::replaceMin(int x)
{
    int root = harr[0];
    harr[0] = x;
    if (root < x)
    {
        MinHeapify(0);
    }
    return root;
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
    {
        smallest = l;
    }
    if (r < heap_size && harr[r] < harr[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void sortK(int arr[], int n, int k)
{
    int *harr = new int[k + 1];
    for (int i = 0; i <= k && i < n; i++)
    {
        harr[i] = arr[i];
    }
    MinHeap hp(harr, k + 1);
    for (int i = 0, j = k + 1; i < n; i++, j++)
    {
        if (j < n)
        {
            arr[i] = hp.replaceMin(arr[j]);
        }
        else
        {
            arr[i] = hp.extractMin();
        }
    }
}

// Driver program to test above functions
int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);

    cout << "Following is sorted arrayn";
    printArray(arr, n);

    return 0;
}