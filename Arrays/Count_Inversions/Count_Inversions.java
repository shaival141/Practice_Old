import java.lang.*;
import java.io.*;
import java.util.*;

public class Count_Inversions
{
    int merge(int[] arr, int l, int m, int r)
    {
        int cnt=0;
        int n1=m-l+1;
        int n2=r-m;
        int[] L = new int[n1];
        int[] R = new int[n2];
        for(int i=0;i<n1;i++)
            L[i]=arr[l+i];
        for(int i=0;i<n2;i++)
            R[i]=arr[m+1+i];
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
                arr[k++]=L[j++];
                cnt+=m-i+1;
            }
        }
        while(i<n1)
        {
            arr[k++]=L[i++];
        }
        while(j<n2)
        {
            arr[k++]=R[j++];
        }
        return cnt;
    }

    int sort(int[] arr,int l, int r)
    {
        int cnt=0;
        if(l<r)
        {
            int m=(l+r)/2;
            cnt+=sort(arr,l,m);
            cnt+=sort(arr,m+1,r);

            cnt+=merge(arr,l,m,r);
        }
        return cnt;
    }

    int count_inversions(int[] arr)
    {
        return sort(arr,0,arr.length-1);
    }

    public static void main(String[] args)
    {
        Count_Inversions cObj = new Count_Inversions();
        int[] arr={1,3,5,2,4,6};
        System.out.println(cObj.count_inversions(arr));
    }
}