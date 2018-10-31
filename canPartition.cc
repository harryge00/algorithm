class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
          sum += nums[i];
        }
        if(sum % 2 == 1) {
          return false;
        }
        int target = sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1));
        dp[0][0] = true;
        for(int i = 0; i < nums.size(); i++) {
          for(int j = 0; j < nums[i] && i > 0; j++) {
            dp[i][j] = dp[i - 1][j];
          }
          for(int j = nums[i]; j <= target; j++) {
            if(i > 0 && dp[i - 1][j]) {
              dp[i][j] = true;
            } else if(dp[i][j - nums[i]]) {
              dp[i][j] = true;
            }
          }
          if(dp[i][target]) {
            return true;
          }
        }
        return false;
    }
};