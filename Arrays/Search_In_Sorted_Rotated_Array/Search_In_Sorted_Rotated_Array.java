import java.util.*;
import java.io.*;
import java.lang.*;

public class Search_In_Sorted_Rotated_Array
{

    int search(int arr[], int key)
    {
        return search_util(arr, key, 0, arr.length-1);
    }

    int search_util(int arr[], int key, int low, int high)
    {
        if(high < low)
            return -1;
        
        int mid = (low+high)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[low] <= arr[mid]) {
            if(key >= arr[low] && key <= arr[mid]) {
                return search_util(arr, key, low, mid-1);
            }
            else {
                return search_util(arr, key, mid+1, high);
            }
        }
        else {
            if(key >= arr[mid] && key <= arr[high]) {
                return search_util(arr, key, mid+1, high);
            }
            else {
                return search_util(arr, key, low, mid-1);
            }
        }
    }

    public static void main(String[] args)
    {
        Search_In_Sorted_Rotated_Array obj = new Search_In_Sorted_Rotated_Array();   
        int arr[] = {5,6,7,8,2,3,4};
        System.out.println(obj.search(arr, 2));
    }
};