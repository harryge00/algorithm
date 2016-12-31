#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
// 0  1   2   3 4 5 6 7 8 9 10 11
// 0  1   2   3 4 5 6 7 8 9 10 11
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	int n = coins.size();
  		vector<int> dp;
  		for(int i = 0; i < amount + 1; i++)
  			dp.push_back(amount + 1);
  		dp[0] = 0;
  		for(int i = 1; i <= amount; i++) {
  			for(int j = 0; j < n; j++) {
  				if(i >= coins[j]) {
	  				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
  				}
  			}
  		}   
  		return dp[amount] <= amount ? dp[amount] : -1;   
    }
};

int main() {
	vector<int> coins{1,2,5};
	Solution s;
	cout<<s.coinChange(coins, 11)<<endl;
}