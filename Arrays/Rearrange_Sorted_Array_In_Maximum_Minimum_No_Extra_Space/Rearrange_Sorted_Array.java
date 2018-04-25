import java.io.*;
import java.lang.*;
import java.util.*;

public class Rearrange_Sorted_Array
{

    static void rearrangeArray(int[] arr)
    {
        int n=arr.length;
        int max_idx=n-1;
        int min_idx=0;
        int max_ele=arr[max_idx]+1;
        for(int i=0;i<n;i++)
        {
            if(i%2==1)
            {
                arr[i]+=(arr[min_idx]%max_ele)*max_ele;
                min_idx++;
            }
            else
            {
                arr[i]+=(arr[max_idx]%max_ele)*max_ele;
                max_idx--;
            }
        }
        for(int i=0;i<n;i++)
        {
            arr[i]/=max_ele;
        }
    }

    public static void main(String[] args)
    {
        int[] arr={1,2,3,4,5,6,7,8,9};
        rearrangeArray(arr);
        System.out.println(Arrays.toString(arr));
    }
};