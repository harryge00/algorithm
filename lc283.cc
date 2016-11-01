class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int leftMostZero, right = n - 1;
        while(right >= 0) {
        	if(!nums[right]) {
        		// find a zero!
        		int curr = right + 1;
        		for(; curr < n; curr++) {
        			if(!nums[curr]) {
        				// right is 0 already.
        				break;
        			} else {
        				// Swap with non-zero numbers
        				nums[curr - 1] = nums[curr];
        			}
        		}
        		nums[curr - 1] = 0;
        	} 
        	right--;
        }
    }
};