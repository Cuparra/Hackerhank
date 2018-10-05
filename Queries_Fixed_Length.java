import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    // Complete the solve function below.
    
    static int[] solve(int[] arr, int[] queries) {
        
        int n       = queries.length;
        int m       = arr.length;
        int[] min   = new int[n];
        
        for(int i=0;i<n;i++){
            
            int d                   = queries[i];
            Queue<Integer> window   = new LinkedList<>();
            
            for(int j=0;j<d;j++)
                window.add(arr[j]);
            
            int max = Collections.max(window); 
            min[i]  = max;
            
            int size    = m -d + 1;
            
            for(int j = 1;j<size;j++){
                
                window.add(arr[j+d-1]);
                
                if(max < arr[j+d-1])
                    max = arr[j+d-1];
                
                if(window.remove() == max)
                    max = Collections.max(window);
                
                if(min[i] > max)
                    min[i] = max;
            }
        }
        
        return min;
    }
    
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nq = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nq[0]);

        int q = Integer.parseInt(nq[1]);

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int arrItr = 0; arrItr < n; arrItr++) {
            int arrItem = Integer.parseInt(arrItems[arrItr]);
            arr[arrItr] = arrItem;
        }

        int[] queries = new int[q];

        for (int queriesItr = 0; queriesItr < q; queriesItr++) {
            int queriesItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            queries[queriesItr] = queriesItem;
        }

        int[] result = solve(arr, queries);

        for (int resultItr = 0; resultItr < result.length; resultItr++) {
            bufferedWriter.write(String.valueOf(result[resultItr]));

            if (resultItr != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
