class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // int arr[] = {10, 7, 8, 9, 1, 5};
        return findElem(nums, 0, nums.size() - 1, k);
    }
    int findElem(vector<int> &nums, int lo, int hi, int k) {
    	if(lo >= hi) return nums[lo];
    	int pivot = nums[hi];
    	int i = lo - 1;
    	for(int j = lo; j < hi ; j++) {
    		if(nums[j] < pivot) {
    			int tmp = nums[++i];
    			nums[i] = nums[j];
    			nums[j] = tmp;
    		}
    	}
    	if(k == i) {
    		return pivot;
    	}
    	nums[hi] = nums[i];
    	nums[i] = pivot;
    	if(k < i) {
    		return findElem(nums, lo, i - 1, k);
    	} else {
    		return findElem(nums, i + 1, hi, k);
    	}
    }
};