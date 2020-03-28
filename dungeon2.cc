class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    	int m = dungeon.size();
    	if(m == 0) {
    		return 1;
    	}
    	int n = dungeon[0].size();
        vector<int> dp(n);
        dp[n - 1] = 1;
     //    dp[n - 1] = 
     //    for(int j = n - 2; j >= 0; j--) {
    	// 	dp[j] = max(dp[j + 1] - dungeon[i][j], 1);
    	// }
    	int tmpMinHP;
        for(int i = m - 1; i >= 0; i--) {
        	dp[n - 1] = max(dp[n - 1] - dungeon[i][n-1], 1);
        	for(int j = n - 2; j >= 0; j--) {
        		if(i == m - 1) {
        			tmpMinHP = dp[j + 1] - dungeon[i][j];
        		} else {
        			tmpMinHP = min(dp[j + 1] - dungeon[i][j], dp[j] - dungeon[i][j]);
        		}
        		dp[j] = max(tmpMinHP, 1);
        	}
        }
        return dp[0];
    }
};