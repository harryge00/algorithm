import java.util.*;
public class nQueen2 {
    public int totalNQueens(int n) {
        int [] locations = new int [n];
        
        return findNext(locations, 0, 0);
    }
    
    private boolean check(int [] locs,int row, int col) {
        for(int i = 0; i < row; i++) {
            if(locs[i] == locs[row] || Math.abs(locs[i]-locs[row]) == row - i)
                return false;
        }
        return true;
    }
    private int findNext(int[] queenLoc, int currRow, int num) {
        for(int col = 0; col < queenLoc.length; col++) {
            queenLoc[currRow] = col;
            if(check(queenLoc, currRow, col)) {
                if(currRow == queenLoc.length - 1) {
                    num++;
                }
                else {
                    num = findNext(queenLoc, currRow+1, num);
                }
            }
        }
        return num;
    }
    public static void main(String [] ddd) {
        nQueen test = new nQueen();
        System.out.println(test.solveNQueens(8));
        
    }
}
