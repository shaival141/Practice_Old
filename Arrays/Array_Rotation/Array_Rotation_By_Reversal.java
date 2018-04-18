import java.lang.*;
import java.util.*;
import java.io.*;

class Array_Rotation_By_Reversal
{

    void reverse_array(int arr[],int start, int end)
    {
        while(start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void rotate_array_left(int arr[],int size, int r)
    {
        reverse_array(arr, 0, r-1);
        reverse_array(arr, r, size-1);
        reverse_array(arr, 0 , size-1);
    }

    void rotate_array_right(int arr[],int size, int r)
    {
        reverse_array(arr, size-r, size-1);
        reverse_array(arr, 0, size-r-1);
        reverse_array(arr, 0 , size-1);
    }

    public static void main(String[] args)
    {
        Array_Rotation_By_Reversal obj = new Array_Rotation_By_Reversal();
        int[] arr = {1,2,3,4,5,6,7,8};
        
        obj.rotate_array_left(arr, 8, 3);
        System.out.println(Arrays.toString(arr));

        obj.rotate_array_right(arr, 8, 2);
        System.out.println(Arrays.toString(arr));
    }
};