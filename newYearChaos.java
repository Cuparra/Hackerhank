import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;



public class Solution {
    
    static void swap(int[] q, int i){
        int temp    = q[i];
        q[i]        = q[i-1];
        q[i-1]      = temp;
    }
    
    // Complete the minimumBribes function below.
    static void minimumBribes(int[] q) {
        int[] count         = new int[q.length];        
        int n               = q.length;
        boolean swapped     = false;
        boolean chaotic     = false;;
        
        do{
            swapped = false;
            for(int i=1;i<n;i++){
                if(q[i-1] > q[i]){
                    swap(q,i);
                    swapped = true;
                    if(++count[q[i]-1] > 2)
                        chaotic = true;
                }
            }
            n = n - 1;
        }while(swapped && !chaotic);
        
        if(chaotic)
            System.out.println("Too chaotic");
        else{
            int sum = 0;
            for(int i=0;i<q.length;i++)
                sum = sum+count[i];
            System.out.println(sum);
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] q = new int[n];

            String[] qItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int qItem = Integer.parseInt(qItems[i]);
                q[i] = qItem;
            }

            minimumBribes(q);
        }

        scanner.close();
    }
}
