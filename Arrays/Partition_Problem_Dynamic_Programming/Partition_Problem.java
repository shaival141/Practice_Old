import java.util.*;
import java.io.*;
import java.lang.*;
public class Partition_Problem
{

    static boolean isPartitionPossible(int arr[])
    {
        int n=arr.length;
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2!=0)
            return false;
        boolean dp[][]=new boolean[sum/2+1][n+1];
        for(int i=0;i<=n;i++)
            dp[0][i]=true;
        for(int i=1;i<=sum/2;i++)
            dp[i][0]=false;
        for(int i=1;i<=sum/2;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(i>=arr[j-1])
                {
                    dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
                }
            }
        }
        return dp[sum/2][n];
    }

    public static void main(String args[])
    {
        int arr[] = {3, 1, 1, 2, 2, 222};
        System.out.println(isPartitionPossible(arr));
    }
}