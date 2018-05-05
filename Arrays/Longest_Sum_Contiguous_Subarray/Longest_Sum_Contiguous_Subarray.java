import java.util.*;
import java.io.*;
import java.lang.*;

public class Longest_Sum_Contiguous_Subarray
{

    static int maxSum(int[] arr)
    {
        int n=arr.length;
        int maxSum=0;
        int maxCur=0;
        int start=0;
        int end=0;
        for(int i=0;i<n;i++)
        {
            maxCur+=arr[i];
            if(maxCur<0)
            {
                maxCur=0;
                start=i+1;
            }
            if(maxCur>maxSum)
            {
                maxSum=maxCur;
                end=i;
            }
        }
        System.out.print(start);
        System.out.print(' ');
        System.out.println(end);
        return maxSum;
    }

    public static void main(String[] args)
    {
        int arr[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
        System.out.println(maxSum(arr));
    }
}