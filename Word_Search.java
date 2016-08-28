import java.util.*;
public class Word_Search {
    public boolean exist(char[][] board, String word) {
        boolean res;
        boolean [][] locs = new boolean[board.length][board[0].length];
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(word.charAt(0) == board[i][j]) {
                    locs[i][j] = true;
                    res = existHelper(board, i, j, 1, word, locs);
                    if(res == true) return true;
                    else    locs[i][j] = false;
                        
                }
            }
        }
        return false;
    }

    private boolean existHelper(char[][] board, int row, int col, int k, String word, boolean[][] locs) {
        if(k >= word.length()) {
            for(int i = 0; i < board.length; i++) {
                for(int j = 0; j < board[0].length; j++) {
                    System.out.print(locs[i][j]+" ");
                }
                System.out.println();
            }
            return true;
        }
        boolean res = false;
        
        int newcol = col + 1;
        if(newcol < board[0].length && board[row][newcol] == word.charAt(k)) {
            if(locs[row][newcol] != true) {
                //have not been visited
                locs[row][newcol] = true;
                res = existHelper(board, row, newcol, k + 1, word, locs);
                if(res == true)
                    return true;
                else
                    locs[row][newcol] = false;
            }
        }
        newcol = col - 1;
        if(newcol >= 0 && board[row][newcol] == word.charAt(k)) {
            if(locs[row][newcol] != true) {

                //have not been visited
                locs[row][newcol] = true;
                res = existHelper(board, row, newcol, k + 1, word, locs);
                if(res == true)
                    return true;
                else
                    locs[row][newcol] = false;
            }
        }
        int newrow = row + 1;
        if(newrow < board.length && board[newrow][col] == word.charAt(k)) {
            if(locs[newrow][col] != true) {
                //have not been visited
                locs[newrow][col] = true;
                res = existHelper(board, newrow, col, k + 1, word, locs);
                if(res == true)
                    return true;
                else
                    locs[newrow][col] = false;
            }
        }
        newrow = row - 1;
        if(newrow >= 0 && board[newrow][col] == word.charAt(k)) {
            if(locs[newrow][col] != true) {
                //have not been visited
                locs[newrow][col] = true;
                res = existHelper(board, newrow, col, k + 1, word, locs);
                if(res == true)
                    return true;
                else
                    locs[newrow][col] = false;
            }
       }
       return false;
    }
    public static void main(String [] a) {
        char[][] board = {
                          "ABCE".toCharArray(),
                          "SFCS".toCharArray(),
                          "ADEE".toCharArray()
                        };
        Word_Search test = new Word_Search();
        String word = "ABCCED";
/*        System.out.println(test.exist(board,word));
        word = "SEE";
        System.out.println(test.exist(board,word));
        word = "ABCD";
        System.out.println(test.exist(board,word));*/
        char[][] board2 = {"aaa".toCharArray(),"abb".toCharArray(), "abb".toCharArray(),"bbb".toCharArray(),"bbb".toCharArray(),
                "aaa".toCharArray(),"bbb".toCharArray(),"abb".toCharArray(),"aab".toCharArray(),"aba".toCharArray()};
        word = "aabaaaabbb";

        System.out.println(test.exist(board2,word));
    }
}
