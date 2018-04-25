import java.util.*;

import com.sun.scenario.effect.Merge;

import java.lang.*;
import java.io.*;

public class Merge_Sort
{
    void merge(int[] arr, int l, int m, int r)
    {
        int n1=m-l+1;
        int n2=r-m;
        int[] L = new int[n1];
        int[] R = new int[n2];

        for(int i=0;i<n1;i++)
        {
            L[i]=arr[i+l];
        }
        
        for(int i=0;i<n2;i++)
        {
            R[i]=arr[i+m+1];
        }

        int i=0, j=0;
        int k=l;
        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            {
                arr[k++]=L[i++];
            }
            else
            {
                arr[k++]=R[j++];
            }
        }
        while(i<n1)
        {
            arr[k++]=L[i++];
        }
        while(k<n2)
        {
            arr[k++]=R[j++];
        }
    }

    void sort(int[] arr, int l, int r)
    {
        if(l<r)
        {
            int m=(l+r)/2;

            sort(arr, l, m);
            sort(arr, m+1, r);

            merge(arr,l,m,r);
        }
    }

    public static void main(String[] args)
    {
        Merge_Sort mObj = new Merge_Sort();
        int[] arr = {5,2,3,19,2,9,10};
        mObj.sort(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
};