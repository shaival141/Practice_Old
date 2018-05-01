import java.util.*;

import com.sun.glass.ui.SystemClipboard;

import java.lang.*;
import java.io.*;

public class Longest_Subarray_With_Sum_k
{

    static int longestSubarrayWithSumK(int[] arr, int k)
    {
        Map<Integer, Integer> myMap = new HashMap<Integer, Integer>();
        int sum=0;
        int maxLen=0;
        int n= arr.length;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==k)
            {
                maxLen = i+1;
            }
            if(myMap.containsKey(sum)==false)
            {
                myMap.put(sum,i);
            }
            if(myMap.containsKey(sum-k))
            {
                if(maxLen<i-myMap.get(sum-k))
                {
                    maxLen=i-myMap.get(sum-k);
                }
            }
        }
        for(Map.Entry<Integer, Integer> entry : myMap.entrySet())
        {
            System.out.println(entry.getKey() + "/" + entry.getValue());
        }
        return maxLen;
    }

    public static void main(String[] args)
    {
        int arr[] = {10, 5, 2, 7, 1, 9};
        System.out.println(longestSubarrayWithSumK(arr, 15));
    }
}