// C program to find length of the longest bitonic subarray
#include<stdio.h>
#include<stdlib.h>
 
int bitonic(int arr[], int n)
{
    int inc[n],dec[n],max;
    inc[0]=1;
    dec[n-1]=1;
    for(int i=1;i<n;i++)
    {
        inc[i] = (arr[i]>arr[i-1]?inc[i-1]+1:1);
    }
    for(int i=n-2;i>=0;i--)
    {
        dec[i] = (arr[i]>arr[i+1]?dec[i+1]+1:1);
    }
    max = dec[0] + inc[0] + 1;
    for(int i=1;i<n;i++)
    {
        if(dec[i]+inc[i]-1>max)
        max = dec[i]+inc[i]-1;
    }
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("nLength of max length Bitnoic Subarray is %d",
            bitonic(arr, n));
    return 0;
}