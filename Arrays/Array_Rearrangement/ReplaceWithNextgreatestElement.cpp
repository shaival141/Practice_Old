// C Program to replace every element with the greatest
// element on right side
#include <stdio.h>

/* Function to replace every element with the
   next greatest element */
void nextGreatest(int arr[], int size)
{
    int maxFromRight = arr[size-1];
    arr[size-1] = -1;
    for(int i=size-2;i>=0;i--)
    {
      int temp = arr[i];
      arr[i]=maxFromRight;
      if(maxFromRight<temp)
      {
        maxFromRight = temp;
      }
    }
}

/* A utility Function that prints an array */
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

/* Driver program to test above function */
int main()
{
  int arr[] = {16, 17, 4, 3, 5, 2};
  int size = sizeof(arr)/sizeof(arr[0]);
  nextGreatest (arr, size);
  printf ("The modified array is: \n");
  printArray (arr, size);
  return (0);
}