// 0  1   2   3 4 5 6 7 8 9 10 11
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	int n = coins.size();
  		vector<int> dp(n+1, amount + 1);
  		dp[0] = 0;
  		for(int i = 1; i <= amount; i++) {
  			for(int j = 0; j < n; j++) {
  				if(i >= coins[j]) {
	  				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
  				}
  			}
  		}   
  		return dp[n] <= amount ? dp[n] : -1;   
    }
};