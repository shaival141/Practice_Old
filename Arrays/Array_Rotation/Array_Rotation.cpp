#include <cstdio>
using namespace std;

// TO-DO : Fix this code

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void rotateArray(int arr[], int n, int d)
{
    int g = gcd(n, d);
    int temp;
    int j;
    if (g == 1)
    {
        
        for (int i = 0; i < g; i++)
        {
            temp = arr[i];
            j = i;
            while (1)
            {
                if (j + d < n)
                {
                    arr[j] = arr[j + d];
                    j += d;
                }
                else
                {
                    arr[n-d+i] = temp;
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < g; i++)
        {
            temp = arr[i];
            j = i;
            while (1)
            {
                if (j + d < n)
                {
                    arr[j] = arr[j + d];
                    j += d;
                }
                else
                {
                    arr[j] = temp;
                    break;
                }
            }
        }
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