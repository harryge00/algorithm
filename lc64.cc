class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(n, 0);
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(i == 0) {
        			if(j > 0) {
	        			row[j] = row[j - 1] + grid[i][j];
        			} else {
	        			row[j] = grid[i][j];
        			}
        		} else if(j == 0) {
        			row[j] = grid[i][j] + row[j];
        		} else {
        			row[j] = grid[i][j] + min(row[j], row[j - 1]);
        		}
        	}
        }
        return row[n - 1];
    }
};