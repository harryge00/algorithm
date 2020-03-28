class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) {
        	return 0;
        }
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
        	for(int j = i; )
        }
    }
};