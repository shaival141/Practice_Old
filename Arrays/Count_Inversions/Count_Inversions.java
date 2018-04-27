import java.lang.*;
import java.io.*;
import java.util.*;

public class Count_Inversions
{
    static long merge(long[] arr, long l, long m, long r)
    {
        long cnt=0;
        long n1=m-l+1;
        long n2=r-m;
        long[] L = new long[(int)n1];
        long[] R = new long[(int)n2];
        for(long i=0;i<n1;i++)
            L[(int)i]=arr[(int)(l+i)];
        for(long i=0;i<n2;i++)
            R[(int)i]=arr[(int)(m+1+i)];
        long i=0, j=0;
        long k=l;
        while(i<n1 && j<n2)
        {
            if(L[(int)i]<=R[(int)j])
            {
                arr[(int)k++]=L[(int)i++];
            }
            else
            {
                arr[(int)k++]=L[(int)j++];
                cnt+=m-i+1;
            }
        }
        while(i<n1)
        {
            arr[(int)k++]=L[(int)i++];
        }
        while(j<n2)
        {
            arr[(int)k++]=R[(int)j++];
        }
        return cnt;
    }

    static long sort(long[] arr,long l, long r)
    {
        long cnt=0;
        if(l<r)
        {
            long m=(l+r)/2;
            cnt+=sort(arr,l,m);
            cnt+=sort(arr,m+1,r);

            cnt+=merge(arr,l,m,r);
        }
        return cnt;
    }

    static long count_inversions(long[] arr)
    {
        return sort(arr,0,arr.length-1);
    }

    public static void main(String[] args)
    {
        try {
            Scanner s = new Scanner(new File("Input.txt"));
            long[] arr = new long[100000];
            for(long i=0;i<100000;i++) {
                arr[(int)i]=s.nextLong();
            }
            System.out.println(count_inversions(arr));
        }
        catch(FileNotFoundException e) {
            System.out.println("Input file not found !!");
        }
    }
}