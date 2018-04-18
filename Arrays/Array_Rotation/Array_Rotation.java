import java.util.*;
import java.lang.*;
import java.io.*;

class Array_Rotation
{

    int gcd(int a,int b)
    {
        if(b==0) {
            return a;
        }
        return gcd(b, a%b);
    }

    void rotateLeft(Integer[] arr, int n, int r)
    {
        int gcd = gcd(n, r);
        for(int i=0 ; i<gcd ; i++)
        {
            int temp = arr[i];
            int j = i;
            while(true)
            {
                int k = j + r;
                if(k >= n) {
                    k -= n;
                }
                if(k == i) {
                    break;
                }   
                arr[j] = arr[k];
                j = k;
            }
            arr[j] = temp;
        }
    }

    void rotateRight(Integer[] arr, int n, int r)
    {
        int gcd = gcd(n,r);
        for(int i=0; i<gcd ; i++)
        {
            int temp = arr[i];
            int j = i;
            while(true)
            {
                int k = j - r;
                if(k < 0) {
                    k += n;
                }
                if(k == i) {
                    break;
                }
                arr[j] = arr[k];
                j = k;
            }
            arr[j] = temp;
        }
    }

    public static void main(String[] args)
    {
        Array_Rotation arrayRotation = new Array_Rotation();
        Integer[] array = {1, 2, 3, 4, 5, 6, 7};
        
        arrayRotation.rotateLeft(array, 7, 3);
        System.out.println(Arrays.toString(array));
        
        arrayRotation.rotateRight(array, 7, 4);
        System.out.println(Arrays.toString(array));
    }
};