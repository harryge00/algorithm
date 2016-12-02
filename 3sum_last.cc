class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());
        int lo = 0;
        int tmp;
        while(lo < nums.size() - 2) {
        	tmp = 0 - nums[lo];
        	int p = lo + 1, q = nums.size() - 1;
        	while(p < q) {
        		if(nums[p] + nums[q] == tmp) {
        			vector<int> triple;
                    triple.push_back(nums[lo]);
                    triple.push_back(nums[p]);
                    triple.push_back(nums[q]);
                    res.push_back(triple);
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
        	lo++;
        	while(lo < nums.size() - 2 && nums[lo] == nums[lo-1]) {
        		lo++;
        	}
        }
        return res;
    }
};