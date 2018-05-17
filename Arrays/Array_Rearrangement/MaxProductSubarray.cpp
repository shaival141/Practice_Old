#include <stdio.h>
 
int min (int x, int y) {return x < y? x : y; }
 
int max (int x, int y) {return x > y? x : y; }
 
int maxSubarrayProduct(int arr[], int n)
{
    int max_ending_here=1,max_till_now=1,min_ending_here=1;
    int temp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            max_ending_here*=arr[i];
            min_ending_here=min(arr[i]*min_ending_here,1);
        }
        else if(arr[i]<0)
        {
            int temp = max_ending_here;
            max_ending_here = max(arr[i]*min_ending_here,1);
            min_ending_here = temp*arr[i];
        }
        else
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }
        if(max_till_now<max_ending_here)
        {
            max_till_now = max_ending_here;
        }
    }
    return max_till_now;
}
 
// Driver Program to test above function
int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Sub array product is %d", 
            maxSubarrayProduct(arr, n));
    return 0;
}
