class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9];
        unordered_set<char> blocks[3][3];
        int r, c;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if(ch != '.') {
                    if(rows[i].find(ch) != rows[i].end()) {
                        return false;
                    } else {
                        rows[i].insert(ch);
                    }
                    if(cols[j].find(ch) != cols[j].end()) {
                        return false;
                    } else {
                        cols[j].insert(ch);
                    }
                    r=i/3;c=j/3;
                    if(blocks[r][c].find(ch) != blocks[r][c].end()) {
                        return false;
                    } else {
                        blocks[r][c].insert(ch);
                    }
                }
            }
        }
        return true;
    }
};