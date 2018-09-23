import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;


class Node{
    
    public ArrayList<Integer> adj;
    
    Node(){
        this.adj = new ArrayList<Integer>();
    }
    
}

public class Solution{
    
    static public void bfs(Node[] arr, int i, boolean[] color, int[] num){
        
        color[i]    = true;
        num[0]      = num[0] + 1; 
        Iterator it = arr[i].adj.iterator();
        
        while(it.hasNext()){
            
            int j = (int) it.next();
            
            if(color[j] == false)
                bfs(arr,j, color,num);    
        
        }
    }
    
    static int[] componentsInGraph(int[][] gb){
        
        int small, great;
        
        int[] num             = new int[2];
        int n                 = 2*(gb.length);
        Node[] arr            = new Node[n];
        boolean[] color       = new boolean[n];
        
        for(int i = 0;i<n;i++)
            arr[i] = new Node();
        
        for(int i = 0;i<n/2;i++){
            arr[gb[i][0]-1].adj.add(gb[i][1]-1);
            arr[gb[i][1]-1].adj.add(gb[i][0]-1);
        }
        
        bfs(arr,gb[0][0]-1, color, num);
        
        great = num[0];
        small = num[0];
        
        for(int i = 1;i<n/2;i++){
            
            
            int k = gb[i][0]-1;
            num[0]  = 0;
            
            if(color[k] == false){
                
                bfs(arr, k, color,num);

                if(num[0] < small)
                    small = num[0];
                if(num[0] > great)
                    great = num[0];
            }
            
        }
        
        int[] temp = new int[2];
        
        temp[0] = small;
        temp[1] = great;
        
        return temp;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(scanner.nextLine().trim());

        int[][] gb = new int[n][2];

        for (int gbRowItr = 0; gbRowItr < n; gbRowItr++) {
            String[] gbRowItems = scanner.nextLine().split(" ");

            for (int gbColumnItr = 0; gbColumnItr < 2; gbColumnItr++) {
                int gbItem = Integer.parseInt(gbRowItems[gbColumnItr].trim());
                gb[gbRowItr][gbColumnItr] = gbItem;
            }
        }

        int[] result = componentsInGraph(gb);

        for (int SPACEItr = 0; SPACEItr < result.length; SPACEItr++) {
            bufferedWriter.write(String.valueOf(result[SPACEItr]));

            if (SPACEItr != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
