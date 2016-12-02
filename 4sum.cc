class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());
        int lo = 0;
        int tmp;
        while(lo < nums.size() - 3) {
        	for(int hi = nums.size() - 1; hi > lo + 2; hi--) {
	        	tmp = 0 - nums[lo] - nums[hi];
	        	int p = lo + 1, q = hi - 1;
	        	while(p < q) {
	        		if(nums[p] + nums[q] == tmp) {
	        			vector<int> quadruplet;
	                    quadruplet.push_back(nums[lo]);
	                    quadruplet.push_back(nums[p]);
	                    quadruplet.push_back(nums[q]);
	                    quadruplet.push_back(nums[hi]);
	                    res.push_back(quadruplet);
	                    q--;
	                    while(q > lo + 1 && nums[q] == nums[q+1]) {
	                    	q--;
	                    }
	        		} else if(nums[p] + nums[q] < tmp) {
	        			p++;
	        		} else {
	        			q--;
	        		}
	        	}
        	}
        	lo++;
        	while(lo < nums.size() - 2 && nums[lo] == nums[lo-1]) {
        		lo++;
        	}
        }
        return res;
    }
};