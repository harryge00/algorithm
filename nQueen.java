import java.util.*;
public class nQueen {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<List<String>> ();
        boolean[][] queenLocations = new boolean[n][n];
        findNext(queenLocations, 0, res);
        return res;
    }
    private void createList(boolean[][] queenLoc, List<List<String>> res) {
        List<String> ans = new ArrayList<String> ();
        for(int i = 0; i < queenLoc.length; i++) {
            StringBuffer line = new StringBuffer();
            for(int j = 0; j < queenLoc[0].length; j++) {
                line.append(queenLoc[i][j]?"Q":".");
            }
            ans.add(line.toString());
        }
        //System.out.println(ans);
        res.add(ans);
    }
    private boolean check(boolean[][] queenLoc,int row, int col) {
        boolean res = false;
        //same row check
        for(int j = 0; j < col; j++) {
            if(queenLoc[row][j]) return false;
        }
        for(int j = col+1; j < queenLoc[0].length; j++) {
            if(queenLoc[row][j]) return false;
        }
        //same col check;
        for(int i = 0; i < row; i++) {
            if(queenLoc[i][col]) return false;
        }
        for(int i = row + 1; i < queenLoc.length; i++) {
            if(queenLoc[i][col]) return false;
        }
        //diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--){
            if(queenLoc[i][j]) return false;
        }
        for(int i = row + 1, j = col + 1; i < queenLoc.length && j < queenLoc[0].length; i++, j++){
            if(queenLoc[i][j]) return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < queenLoc[0].length; i--,j++){
            if(queenLoc[i][j]) return false;
        }
        for(int i = row + 1, j = col - 1; i < queenLoc.length && j >= 0; i++, j--){
            if(queenLoc[i][j]) return false;
        }
        return true;
    }
    private void findNext(boolean[][] queenLoc, int currRow, List<List<String>> res) {
        for(int col = 0; col < queenLoc[0].length; col++) {
            if(check(queenLoc, currRow, col)) {
                //this location is ok
                queenLoc[currRow][col] = true;
                if(currRow == queenLoc.length - 1) {
                    createList(queenLoc, res);
                }
                else {
                    findNext(queenLoc, currRow+1, res);
                }
            }
            else {

            }
            queenLoc[currRow][col] = false;
        }
    }
    public static void main(String [] ddd) {
        nQueen test = new nQueen();
        System.out.println(test.solveNQueens(8));
        
    }
}
