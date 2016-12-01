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
	void helper(vector<int>& coins, int cur, int count, int remain) {
		if(remain < 0) return;
		if(coins[cur] == remain) {
			if(count < min) {
				min = count;
				found = true;
			}
			return;
		} else if (coins[cur] > remain) {
			while(cur >= 0 && coins[cur] > remain) {
				cur--;
			}
		}
		while(cur>=0) {
			helper(coins, cur, count+1, remain - coins[cur]);
			cur--;
		}
	}
    int coinChange(vector<int>& coins, int amount) {
    	sort(coins.begin(), coins.end());
        found = false;
        min = INT_MAX;
        helper(coins, coins.size() - 1, 0, amount);
	    return found?min:-1;
    }
};

int main() {
	vector<int> coins{1,2,5};
	Solution s;
	cout<<s.coinChange(coins, 11)<<endl;
}