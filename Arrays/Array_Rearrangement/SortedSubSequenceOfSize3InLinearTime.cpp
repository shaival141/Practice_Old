// C/C++ program to find a sorted subsequence of size 3
#include<stdio.h>
 
// A function to fund a sorted subsequence of size 3
void find3Numbers(int arr[], int n)
{
    int greater[n];
    int smaller[n];
    int i;
    for(int i=0;i<n;i++)
    {
        greater[i]=-1;
        smaller[i]=-1;
    }
    //find smaller elements in left
    int min=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<=arr[min])
        {
            min = i;
            smaller[i]=-1;
        }
        else
        {
            smaller[i]=min;
        }
    }
    //find larger elements in right
    int max=n-1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=arr[max])
        {
            max = i;
            greater[i]=-1;
        }
        else
        {
            greater[i]=max;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(smaller[i]!=-1 && greater[i]!=-1)
        {
            printf("%d %d %d\n",arr[smaller[i]],arr[i],arr[greater[i]]);
        }
    }
}
 
// Driver program to test above function
int main()
{
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    find3Numbers(arr, n);
    return 0;
}