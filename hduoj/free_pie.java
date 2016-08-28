import java.util.*;
public class free_pie {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int tests = cin.nextInt();
        int [] dp = new int[11];
        int [] tmp = new int[11];
        int [][] arr = new int [tests][11];
        int maxTime = 0;
        for(int t = 0; t < tests; t++) {
            int x = cin.nextInt();
            int time = cin.nextInt();
            if(time > maxTime) maxTime = time;
            arr[time][x]++;
        }
        cin.nextInt();
        for(int j = 0; j < 11; j++) {
            dp[j] = arr[maxTime][j];
        }
        for(int i = maxTime - 1; i >= 0; i--) {
            tmp[0] = (dp[0] > dp[1] ? dp[0] : dp[1]) + arr[i][0];
            for(int j = 1; j < 10; j++) {
                tmp[j] = find3Max(dp[j - 1], dp[j], dp[j + 1])+arr[i][j];
            }
            tmp[10] = (dp[9] > dp[10] ? dp[9] : dp[10]) + arr[i][10];
            dp = tmp;
        }
            System.out.println(dp[5]);
            
        
    }
    private static int find3Max(int a, int b, int c) {
        if(a > b) {
            return a > c? a:c;
        }
        else {
            return b > c? b:c;
        }
    }
    
}
