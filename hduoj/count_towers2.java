import java.util.*;
public class count_towers2 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int [] dp;
        int tests = cin.nextInt();
        for(int t = 0; t < tests; t++) {
            int lines = cin.nextInt();
            dp = new int[lines];
            int [][] arr = new int[lines][lines]; 
            for(int i = 0; i < lines; i++) {
               for(int j = 0; j <= i; j++) {
                   arr[i][j] = cin.nextInt();
               }
            }
            for(int i = lines - 1; i >= 0; i--) {
               if(i < lines - 1) {
                   for(int j = 0; j <= i; j++) {
                       dp[j] = (dp[j] > dp[j + 1] ? dp[j]:dp[j + 1]) + arr[i][j];
                   }
               }
               else {
                   for(int j = 0; j <= i; j++) {
                       dp[j] = arr[i][j];
                   }
               }
            }
            System.out.println(dp[0]);
            
        }
    }
    private static int findMax(int [] array) {
    int max = array[0];
    for (int i = 1; i < array.length; i++) {
        if (array[i] > max) {
          max = array[i];
        }
    }
    return max;
}
    private static void print2dArr(int [][] array) {
        System.out.println();
        for (int i = 0; i < array.length; i++) {
            for(int j = 0; j < array[0].length; j++) {
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
    }
}
