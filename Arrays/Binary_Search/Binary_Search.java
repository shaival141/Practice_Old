import java.lang.*;
import java.io.*;
import java.util.*;

class Binary_Search
{

    int search(int[] arr, int key)
    {
        int left = 0;
        int right = arr.length-1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(arr[mid] == key) {
                return mid;
            }
            if(arr[mid] < key) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        Binary_Search obj = new Binary_Search();
        int[] arr = {1,4,6,9,10,19,21,24};
        System.out.println(obj.search(arr, 6));
    }
};