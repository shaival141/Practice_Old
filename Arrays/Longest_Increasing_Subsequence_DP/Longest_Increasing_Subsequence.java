import java.util.*;
import java.io.*;
import java.lang.*;

public class Longest_Increasing_Subsequence
{

    static int LIS(int[] arr)
    {
        int n=arr.length;
        int[] lis = new int[n];
        int[] lds = new int[n];
        for(int i=0;i<n;i++)
        {
            lis[i]=1;
            lds[i]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                {
                    lis[i]=lis[j]+1;
                }
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(arr[i]>arr[j] && lds[i]<lds[j]+1)
                {
                    lds[i]=lds[j]+1;
                }
            }
        }
        
        int max=1;
        for(int i=0;i<n;i++)
        {
            if(max<lis[i]+lds[i]-1)
            {
                max=lis[i]+lds[i]-1;
            }
        }
        return max;
    }

    public static void main(String[] args)
    {
        int[] arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
        int[] arr2 = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
        System.out.println(LIS(arr));
        System.out.println(LIS(arr2));
    }
};