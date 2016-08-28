
import java.io.*;
import java.util.*;
public class didi2
{
    private static int findSum(int x, int[] arr) {
         int res = 0;
		 for(int i = x; i < arr.length; i++){
              res+= arr[i];
              if(res == 0)
                    return i - x + 1;
         }
          return 0;
    }
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        
        int col = 0;
        int [] arr = new int[1000];

         
         while(cin.hasNextInt()) {
             arr[col++]=cin.nextInt();
         }
             
             for(int i = 0; i < col; i++) {
                 System.out.print(arr[i]+" ");
             }
                 System.out.println(" ");
        int max = 0, begin = -1;
            for(int j = 0; j < col; j++) {
                int tmp = findSum(j, arr);
                 if(tmp > max) {
                       begin = j;
                       max = tmp;
                 }
                
            }
        if(begin >= 0) {
              for(int i = begin; i < begin + max; i++) {
                    System.out.print(arr[i]);
                    if(i != begin + max -1)
                          System.out.print(" ");
              }
              System.out.println();
        }
        
    }

}
