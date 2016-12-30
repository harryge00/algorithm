#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
class Solution {
private:
	int min;
	bool found;
public:
    bool helper(vector<int>& coins, int cur, int count, int remain) {
		cout<<coins[cur]<<"cur:"<<cur<<","<<count<<","<<remain<<endl;
		if(remain < 0) return false;
		if(remain == 0) {
			if(count < min) {
				min = count;
			}
	        return true;
		}
		while(cur>=0) {
			if(helper(coins, cur, count+1, remain - coins[cur])) {
				return true;
			}
			cur--;
		}
		return false;
	}
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
    	sort(coins.begin(), coins.end());
        found = false;
        min = INT_MAX;
	    return (helper(coins, coins.size() - 1, 0, amount))?min:-1;
    }
};

int main() {
	vector<int> coins{1,2,5};
	Solution s;
	cout<<s.coinChange(coins, 11)<<endl;
	vector<int> coins2{186,419,83,408};
	cout<<s.coinChange(coins2, 6249)<<endl;
}
//[186,419,83,408]
// 6249