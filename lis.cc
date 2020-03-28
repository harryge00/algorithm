class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    if(dp[i] > res) {
                        res = dp[i];

                    }
                }
            }
        }
        return res;
    }
};

/*
10 11 2 5 7 9 1 2 3 4 5 6
*/