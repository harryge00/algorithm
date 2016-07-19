class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        while(lo < hi) {
    		mid = (lo + hi) / 2;
    		if(target == nums[mid]) {
    			return mid;
    		}
        	if(nums[lo] < nums[hi]) {
        		if(target < nums[mid]) {
        			hi = mid - 1;
        		} else {
        			lo = mid + 1;
        		}
        	} else {
        		if(target > nums[mid]) {
        			if(nums[mid] > nums[hi]) {
        				lo = mid + 1;
        			} else {
        				if(target <= nums[hi]) {
	        				lo = mid + 1;
        				} else {
	        				hi = mid - 1;
        				}
        			}
        		} else {
        			//target < nums[mid]
        			if(nums[mid] < nums[lo]) {
        				hi = mid - 1;
        			} else {
        				if(target >= nums[lo]) {
	        				hi = mid - 1;
        				} else {
	        				lo = mid + 1;
        				}
        			}
        		}
        	}
        }
        if(nums[lo] == target) return lo;
        return -1;
    }
};