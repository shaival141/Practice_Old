#include<stdio.h>

int kadane(int arr[],int n)
{
    int max_sum_till_now=0,max_ending_here=0;
    for(int i=0;i<n;i++)
    {
        max_ending_here+=arr[i];
        if(max_ending_here<0)
        max_ending_here = 0;
        if(max_sum_till_now<max_ending_here)
        max_sum_till_now = max_ending_here;
    }
    return max_sum_till_now;
}

int maxCircularSum(int arr[],int n)
{
    int wrappingSum = kadane(arr,n);
    int totalSum = 0;
    for(int i=0;i<n;i++)
    {
        totalSum+=arr[i];
        arr[i]=-arr[i];
    }
    int nonWrappingSum = totalSum + kadane(arr,n);
    if(wrappingSum<nonWrappingSum)
    {
        return nonWrappingSum;
    }
    else
    {
        return wrappingSum;
    }
}
 
int main()
{
    int a[] =  {11, 10, -20, 5, -3, -5, 8, -13, 10};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Maximum circular sum is %d\n",maxCircularSum(a, n));
    return 0;
}