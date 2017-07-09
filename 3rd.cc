class Solution {
public:
    int thirdMax(vector<int>& nums) {
    	long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
    	for(int i = 0; i < nums.size(); i++) {
    		c = nums[i];
    		if(c > b) swap(c, b);
    		if(b > a) swap(b, a);
    	}
        return c == LONG_MIN? a: c;
    }
};