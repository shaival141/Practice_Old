import java.util.*;
import java.io.*;
import java.lang.*;

public class Find_Minimum
{

    int find_minimum(int[] arr)
    {
        return search_util(arr, 0, arr.length-1);
    }

    int search_util(int[] arr, int low, int high)
    {
        if(low > high)
            return arr[0];
        if(low == high)
            return arr[low];
        
        int mid = (low+high)/2;
        
        if(mid < high && arr[mid+1]<arr[mid]) {
            return arr[mid+1];
        }
        if(mid > low && arr[mid]<arr[mid-1]) {
            return arr[mid];
        }

        if(arr[high] > arr[mid]) {
            return search_util(arr, low, mid-1);
        }
        return search_util(arr, mid+1, high);
    }

    public static void main(String[] args)
    {
        Find_Minimum findMinimumObj = new Find_Minimum();
        int[] array = {32,33,45,56,1,5,7,10,19,29,31};
        System.out.println(findMinimumObj.find_minimum(array));
    }
}