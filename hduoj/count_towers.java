import java.util.*;
public class count_towers {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int [][] dp;
        int tests = cin.nextInt();
        for(int t = 0; t < tests; t++) {
            int lines = cin.nextInt();
            dp = new int[lines][lines];
            int [] arr = new int[100]; 
            for(int i = 0; i < lines; i++) {
               for(int j = 0; j <= i; j++) {
                   arr[j] = cin.nextInt();
               }
               if(i>0) dp[i][0] = dp[i - 1][0] + arr[0];//default int array value 0?
               else dp[i][0] = arr[0];
                   
               if(i > 1) 
                   dp[i][i] = dp[i - 1][i - 1] + arr[i];
               for(int j = 1; j < i; j++) {
                   dp[i][j] = (dp[i - 1][j - 1] > dp[i - 1][j]?dp[i - 1][j - 1]:dp[i - 1][j]) + arr[j];
               }
               

            }
            System.out.println(findMax(dp[lines - 1]));
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
