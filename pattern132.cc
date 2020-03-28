class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) {
            return false;
        }
        int min = nums[0];
        for(int i = 2; i < n; i++) {
            if(nums[i] < max && nums[i] > min) {
                return true;
            }
            if(nums[i] > max) {
                max = nums[i];
            } else if(nums[i] < min) {
                min = nums[i];
            }
        }
        return false;
    }
};