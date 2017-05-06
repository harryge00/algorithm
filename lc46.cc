#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
public:
	void helper(vector<int> one, vector<int>& remains) {
		if(remains.size() == 0) {
			res.push_back(one);
			return;
		} else {
			for(vector<int>::iterator it = remains.begin(); it != remains.end(); it++) {
				int back = *it;
				one.push_back(*it);
				remains.erase(it);
				helper(one, remains);
				remains.insert(it, back);
				one.pop_back();
			}
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
    	for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
    		vector<int> one;
    		one.push_back(*it);
    		int back = *it;
    		nums.erase(it);
    		helper(one, nums);
    		nums.insert(it, back);
    	}
    	return res;
    }
};

int main()
{
	vector<int> nums{1,2,3};
	Solution s;
	vector<vector<int>> res = s.permute(nums);
	for(auto &one : res) {
		for(auto &i : one) {
			cout<< i <<",";
		}
		cout<<endl;
	}
}