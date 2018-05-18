/* Dynamic Programming implementation of longest bitonic subsequence problem */
#include<stdio.h>
#include<stdlib.h>
 
/* lbs() returns the length of the Longest Bitonic Subsequence in
    arr[] of size n. The function mainly creates two temporary arrays
    lis[] and lds[] and returns the maximum lis[i] + lds[i] - 1.
 
    lis[i] ==> Longest Increasing subsequence ending with arr[i]
    lds[i] ==> Longest decreasing subsequence starting with arr[i]
*/
int lbs( int arr[], int n )
{
    int i,j;

    int lis[n];
    int lds[n];
    for(i=0;i<n;i++)
    lis[i]=1;
    for(i=0;i<n;i++)
    lds[i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && lis[i]<lis[j]+1)
            lis[i]=lis[j]+1;
        }
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
            if(arr[j]<arr[i] && lds[i]<lds[j]+1)
            lds[i]=lds[j]+1;
        }
    }
    int max=0;
    for(i=0;i<n;i++)
    {
        if(lis[i]+lds[i]-1>max)
        {
            max =lis[i] + lds[i] - 1;
        }
    }
    return max;
}
 
/* Driver program to test above function */
int main()
{
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs( arr, n ) );
  return 0;
}