class Solution {
public:
    int findMin(vector<int>& nums) {
    	/*
Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7, 8,9,2, 4]
Input: [14,52,1,2, 3,4,5, 6]
Output: 0
10 2 3 4 5
Ai > Ai+1
    	*/
    	int l = 0, r = nums.size();
    	int mid;
    	while(l < r) {
    		mid = (l + r) / 2;
    		if(nums[mid] < nums[l]) {
    			if(mid == l + 1) {
    				return nums[mid];
    			} else {
    				r = mid - 1;
    			}
    		} else {
    			l = mid + 1;
    		}
    	}
        return 0;
    }
};