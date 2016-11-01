class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
    	int n = nums.size();
        vector<int> dp(n, 1);
        dp[n - 1] = 1;
        for(int i = n - 1; i > 0; i--) {
        	for(int j = i - 1; j >= 0; j--) {
        		if(nums[j] < nums[i] && dp[j] < dp[i] + 1) {
        			dp[j] = dp[i] + 1;
        		}
        	}
        }
        int max = 0;
        for(int i = 0; i < n; i++) {
        	if(dp[i] > max) {
        		max = dp[i];
        	}
        }
    	return max;
    }
};