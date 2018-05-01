import java.util.*;
import java.lang.*;
import java.io.*;

public class Form_Minimum_Number_From_Sequence
{

    static void FormSequence(String sequence)
    {
        String ans="";
        Stack<Integer> stck = new Stack<Integer>();
        for(int i=0;i<=sequence.length();i++)
        {
            stck.push(i+1);
            if(i==sequence.length() || sequence.charAt(i)=='I')
            {
                while(!stck.isEmpty())
                {
                    ans+=stck.peek().toString();
                    stck.pop();
                }
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args)
    {
        FormSequence("IDID");
        FormSequence("I");
        FormSequence("DD");
        FormSequence("II");
        FormSequence("DIDI");
        FormSequence("IIDDD");
        FormSequence("DDIDDIID");
    }
}