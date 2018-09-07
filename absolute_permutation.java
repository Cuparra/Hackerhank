import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the absolutePermutation function below.
    static int[] absolutePermutation(int n, int k) {
        
        int[] arr     = new int[n];
        boolean[] ch  = new boolean[n];
        int size      = n/2;
        int count     = 0;
        
        for(int i = 1; i + k  - 1 < n ; i++){
            //System.out.printf("%d %d %d\n", i, i+k-1, n);
            if(!ch[i-1]){
                arr[i-1]    = i+k;
                arr[i+k-1]  = i;
                ch[i-1]     = true;
                ch[i+k-1]   = true;
                count       = count + 2;
            } 
        }
        
        if(k == 0)
            return arr;
        
        if(count != n){
            int[] temp  = new int[1];
            temp[0]     = -1;
            return temp;
        }
        
        return arr;   
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] nk = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nk[0]);

            int k = Integer.parseInt(nk[1]);

            int[] result = absolutePermutation(n, k);

            for (int i = 0; i < result.length; i++) {
                bufferedWriter.write(String.valueOf(result[i]));

                if (i != result.length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
