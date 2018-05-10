// A O(n) program to find the largest subarray 
// with equal number of 0s and 1s
 
#include <stdio.h>
#include <stdlib.h>
  
// A utility function to get maximum of two 
// integers
 
int max(int a, int b) { return a>b? a: b; }
  
// This function Prints the starting and ending 
// indexes of the largest subarray with equal
// number of 0s and 1s. Also returns the size
// of such subarray.
 
int findSubArray(int arr[], int n)
{
    int sumLeft[n],max,min,i;
    sumLeft[0]=(arr[0]==0?-1:1);
    max = sumLeft[0],min=sumLeft[0];
    for(int i=1;i<n;i++)
    {
        sumLeft[i]=sumLeft[i-1]+(arr[i]==0?-1:1);
        if(sumLeft[i]<min)
        min = sumLeft[i];
        else if(sumLeft[i]>max)
        max = sumLeft[i];
    }
    int hashTable[max-min+1];
    int maxSize = -1,startIndex;
    for(i=0;i<max-min+1;i++)
    hashTable[i]=-1;

   for(i=0;i<n;i++)
    {
        if(sumLeft[i]==0)
        {
            startIndex = 0;
            maxSize = i + 1;
        }
        if(hashTable[sumLeft[i]-min]==-1)
        {
            hashTable[sumLeft[i]-min]=i;
        }
        else if(i-hashTable[sumLeft[i]-min]>maxSize)
        {
            maxSize = i - hashTable[sumLeft[i]-min];
            startIndex = hashTable[sumLeft[i]-min] + 1;
        }
    }

    if (maxSize == -1)
        printf("No such subarray");
    else
        printf("%d to %d", startIndex, startIndex+maxSize-1);
  
    return maxSize;
}
  
/* Driver program to test above functions */
int main()
{
    int arr[] =  {1, 0, 0, 1, 0, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
  
    findSubArray(arr, size);
    return 0;
}
