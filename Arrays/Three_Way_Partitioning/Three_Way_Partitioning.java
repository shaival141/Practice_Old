import java.util.*;

import com.sun.javafx.collections.ElementObservableListDecorator;

import java.io.*;
import java.lang.*;

public class Three_Way_Partitioning
{

    static void threeWayPartition(int[] arr, int lowKey, int highKey)
    {
        int n=arr.length;
        int start=0;
        int end=n-1;
        for(int i=0;i<=end;)
        {
            if(arr[i]<lowKey)
            {
                int temp=arr[start];
                arr[start]=arr[i];
                arr[i]=temp;
                start++;
                i++;
            }
            else if(arr[i]>highKey)
            {
                int temp=arr[end];
                arr[end]=arr[i];
                arr[i]=temp;
                end--;
            }
            else
            {
                i++;
            }
        }
    }

    public static void main(String[] args)
    {
        int[] arr = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
        int lowKey = 10;
        int highKey = 20;
        threeWayPartition(arr, lowKey, highKey);
        System.out.println(Arrays.toString(arr));
    }
};