#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;
class Solution {
private:
	int kk;
    vector<vector<int> > result;
public:
    vector<vector<int> > combine(int n, int k) {
        kk=k;
        vector<int> nums;
        queue<int> remains;
        for(int i = 1; i <= n; i++) {
        	remains.push(i);
        }
        helper(nums, remains);
        return result;
    }
    void helper(vector<int> nums, queue<int> remains) {
    	if(nums.size() == kk) {
    		result.push_back(nums);
    		return;
    	}
    	int tmp;
    	while(remains.empty() == false) {
    		nums.push_back(remains.front());
    		remains.pop();
    		if(nums.size() + remains.size() < kk) return;
    		helper(nums, remains);
    		nums.pop_back();
    	}
    }
};
void print2dVector(vector<vector<int> > arr) {
	for(int i = 0; i < arr.size(); i++) {
		for(int j = 0; j < arr[i].size(); j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main() {
	vector<vector<int> > result;
	Solution s;
	result = s.combine(2, 1);
	print2dVector(result);
	result = s.combine(5,3);
	print2dVector(result);
	result = s.combine(6,4);
	print2dVector(result);


}