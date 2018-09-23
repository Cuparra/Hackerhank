import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner in          = new Scanner(System.in);
        Stack<Integer>  stk = new Stack<Integer>();
        int max             = 1;
        int q               = in.nextInt();
        boolean flag        = false;
        
        int[] arr           = new int[q];
        
        while(q-- != 0){
            
            int a = in.nextInt();
            
            if(a == 1){
                
                int elem = in.nextInt();
                stk.push(elem);
                
                if(elem > max)
                    max = elem;
            
            }else if(a == 2){
                stk.pop();
                max = 1;
                flag = true;
            }
            else{
                
                Iterator it = stk.iterator();
               
                if(flag){
                    
                    while(it.hasNext()){

                        int elem = (int) it.next();
                        if(max < elem)
                            max = elem;
                    }
                    flag = false;
                }

                System.out.printf("%d\n", max);
            }
        }
        
    }
}
