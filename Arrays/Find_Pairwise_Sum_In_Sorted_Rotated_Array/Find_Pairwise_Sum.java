import java.lang.*;
import java.io.*;
import java.util.*;

public class Find_Pairwise_Sum
{

    int findPairwiseSum(int[] arr, int sum)
    {
        int n = arr.length;
        if(n == 1) {
            return -1;
        }
        int i=0;
        for(i=0 ; i<n-1 ; i++) {
            if(arr[i] > arr[i+1]) {
                break;
            }
        }
        int l=(i+1)%n;
        int r=i;
        while(l!=r) {
            if(arr[l] + arr[r] == sum) {
                return 1;
            }
            if(arr[l] + arr[r] > sum) {
                r = (r+n-1)%n;
            }
            else {
                l = (l+1)%n;
            }
        }
        return 0;
    }

    public static void main(String[] args)
    {
        Find_Pairwise_Sum f = new Find_Pairwise_Sum();
        string s1="a";
        string s2="a";
        int[] array = {1,4,5,6,7,10,19};
        System.out.println(f.findPairwiseSum(array, 12));
    }
};