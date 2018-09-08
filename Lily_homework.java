import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int numOfSwap(int [] arr, int n){
        
        int swap                        = 0;
        int[] copy                      = arr.clone();
        HashMap<Integer, Integer> map   = new HashMap<Integer, Integer>();
        
        for(int i = 0;i<n;i++)
            map.put(arr[i],i);
        
        Arrays.sort(arr);
        
        for(int i = 0;i<n;i++){
            //System.out.println(Arrays.toString(copy));
            if(copy[i] != arr[i]){
                int index   = map.get(arr[i]);
                //System.out.println(i + " "+index +" "+ arr[i] + " " + copy[i]);
                int temp    = copy[i];
                copy[i]     = arr[i];
                copy[index] = temp;
                map.put(temp,index);
                ++swap;
            }
        }
        
        return swap;
    }
    
   static int lilysHomework(int[] arr) {
        
        int n = arr.length;
        
        int[] arr1  = arr.clone();
        int x       = numOfSwap(arr1,n);
        
       int[] arr2  = arr.clone();
        for(int i=0;i<n;i++){
            arr2[i]*=-1;
        }
       
        int y       = numOfSwap(arr2,n);
        
        if(x < y)
            return x;
        else 
           return y;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = lilysHomework(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
