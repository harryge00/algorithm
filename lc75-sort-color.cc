class Solution {
    // [2,0,2,1,0, 1,0]
    /* 
    0 0,2,1,0, 1 2  1 x
    0 0,2,1,0, 1 2  2 
    0 0,1,1,0, 2 2
    0 0,1,1,0, 2 2
    0 0,1,1,0, 2 2
    */
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int i = 0;
        while(i < r) {
            if(nums[i] == 0 && i > l) {
                swap(nums[i], nums[l]);
                l++;
            } else if(nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
            } else {
                i++;
            }
        }
        
        return;
    }
};