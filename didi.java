
import java.io.*;
import java.util.*;
public class didi
{
    private int findSum(int x, int y, int[][] arr) {
        return arr[x][y] + arr[x][y+1] + arr[x+1][y] + arr[x+1][y+1];
    }
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int row = 0;
        int col = 0;
        int [][] arr = new int[100][100];

        String str = cin.nextLine();
             for(int i = 0; i < str.length(); i++) {
                 char c = str.charAt(i);
                 if(c==';') {
                     col = 0;
                     row++;
                     continue;
                 }
                 if(c==' ') {
                     continue;
                 }
                 arr[row][col++] = c - '0';
             }
        int max = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col - 1; j++) {
                int tmp = findSum(i, j, arr);
                max = (max > tmp ? max : tmp);
            }
        }
        return max;
    }
}

