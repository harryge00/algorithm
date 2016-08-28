import java.util.*;
public class free_pie2 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int tests = cin.nextInt();
        int [] dp = new int[11];
        int [] tmp = new int[11];
        int [][] arr = new int [100000][11];
        int maxTime = 0;
        for(int t = 0; t < tests; t++) {
            int x = cin.nextInt();
            int time = cin.nextInt();
            if(maxTime < time) {
                maxTime = time;
            }
            arr[time][x]++;
        }
        while(cin.hasNext())        cin.nextInt();
        for(int i = 0; i < 11; i++) {
            dp[i] = arr[maxTime][i];
        }
        for(int i = maxTime - 1; i >= 0; i--) {
            
            for(int j = 1; j < 10; j++) {
                tmp[j] = arr[i][j] + Math.max(dp[j - 1], Math.max(dp[j], dp[j + 1]));
            }
            tmp[0] = arr[i][0] + Math.max(dp[0], dp[1]);
            tmp[10] = arr[i][10] + Math.max(dp[10], dp[9]);
            //printArray.printArr(tmp);
            dp = tmp;
        }
            System.out.println(dp[5]);
            
        
    }
    
}
