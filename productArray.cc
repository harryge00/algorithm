class Solution {
public:
    // 2    1   3 5  4
    // 2    2   6 30 120
    // 1    2   2 6  30
    //  60    120     40  24   30  
    // 120  60 60 20 4 
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        vector<int> l(n);
        vector<int> r(n);
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                l[i] = nums[i];
                r[n - i - 1] = nums[n - 1 - i];
            } else {
                l[i] = l[i - 1] * nums[i];
                r[n - i - 1] = r[n - i] * nums[n - 1 - i];
            }
        }
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                res[i] = r[i + 1];
            } else if(i == n - 1) {
                res[i] = l[i - 1];
            } else {
                res[i] = l[i - 1] * r[i + 1];
            }
        }
        return res;
    }
};