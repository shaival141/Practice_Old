import java.util.*;
import java.io.*;
import java.lang.*;

public class Find_Missing_Repeating_Numbers {

    static void printMissingRepeating(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[Math.abs(arr[i]) - 1] < 0) {
                System.out.print("Repeating Number : ");
                System.out.println(Math.abs(arr[i]));
            } else {
                arr[Math.abs(arr[i]) - 1] = -arr[Math.abs(arr[i]) - 1];
            }
        }
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 0) {
                System.out.print("Missing Number : ");
                System.out.println(i + 1);
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = { 7, 3, 4, 1, 1, 6, 2 };
        printMissingRepeating(arr);
    }
}