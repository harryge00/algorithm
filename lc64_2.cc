class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if !grid || grid[0].size() ==0 {
    		return 0;
    	}
    	int m = grid.size(), n = grid[0].size();
        vector<int> row(n);
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(j==0){
        			row[j] += grid[i][j];
        		} else {
        			row[j] = min(row[j-1], row[j]) + grid[i][j];
        		}
        	}
        }
        return row[grid.]
    }
};