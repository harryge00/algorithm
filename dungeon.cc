class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0) {
        	return 1;
        }
        int n = dungeon[0].size();
        vector<vector<int>> minHPs(m, vector<int>(n));
        minHPs[m - 1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 1 : 1 - dungeon[m - 1][n - 1];
        dfs(dungeon, minHPs, m - 1, n - 1);
        return minHPs[0][0];
        /* -3 4 -2 -5
        */
    }
    void dfs(vector<vector<int>>& dungeon, vector<vector<int>>& minHPs, int x, int y) {
    	if(x > 0) {
    		if(!minHPs[x - 1][y] || minHPs[x][y] - dungeon[x - 1][y] < minHPs[x - 1][y]) {
    			minHPs[x - 1][y] = minHPs[x][y] - dungeon[x - 1][y] <= 0 ? 1 : minHPs[x][y] - dungeon[x - 1][y];
    		}
    		dfs(dungeon, minHPs, x - 1, y);
    	}
    	if(y > 0) {
    		if(!minHPs[x][y - 1] || minHPs[x][y] - dungeon[x][y - 1] < minHPs[x][y - 1]) {
    			minHPs[x][y - 1] = minHPs[x][y] - dungeon[x][y - 1] <= 0 ? 1 : minHPs[x][y] - dungeon[x][y - 1];
    		}
    		dfs(dungeon, minHPs, x, y - 1);
    	}
    	return;
    }
};