import java.util.*;
import java.io.*;
import java.lang.*;
public class Longest_Bitonic_Subarray
{

    static int longestBitonicSubarray(int[] arr)
    {
        int n=arr.length;
        int[] inc = new int[n];
        int[] dec = new int[n];
        inc[0]=1;
        dec[n-1]=1;
        for(int i=1;i<n;i++)
        {
            inc[i]=(arr[i]>=arr[i-1]) ? inc[i-1]+1 : 1;
        }
        for(int i=n-2;i>=0;i--)
        {
            dec[i]=(arr[i]>=arr[i+1]) ? dec[i+1]+1 : 1;
        }
        int max = 1;
        for(int i=0;i<n;i++)
        {
            if(max<dec[i]+inc[i]-1)
                max=dec[i]+inc[i]-1;
        }
        return max;
    }

    public static void main(String[] args)
    {
        int arr[] = {12, 4, 78, 90, 45, 23};
        System.out.println(longestBitonicSubarray(arr));
    }
};