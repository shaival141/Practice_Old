import java.util.*;

import javax.lang.model.util.ElementScanner6;

import java.lang.*;
import java.io.*;

public class Longest_Product_Contiguous_Subarray
{

    static int min(int a, int b)
    {
        if(a<b)
            return a;
        return b;
    }

    static int max(int a, int b)
    {
        if(a>b)
            return a;
        return b;
    }

    static int maxProduct(int[] arr)
    {
        int maxCur=1;
        int minCur=1;
        int maxProd=1;
        int n=arr.length;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                maxCur*=arr[i];
                minCur=min(minCur*arr[i],1);
            }
            else if(arr[i]==0)
            {
                maxCur=1;
                minCur=1;
            }
            else
            {
                int temp=maxCur;
                maxCur=max(minCur*arr[i],1);
                minCur=temp*arr[i];
            }
            maxProd=max(maxProd, maxCur);
        }
        return maxProd;
    }

    public static void main(String[] args)
    {
        int arr[] = {1, -2, -3, 0, 7, -8, -2};
        System.out.println(maxProduct(arr));
    }
}