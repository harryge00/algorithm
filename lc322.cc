class Solution {
private:
	int min;
	bool found;
public:
	void helper(vector<int>& coins, int cur, int count, int remain) {
		if(remain < 0) return;
		if(coins[cur] == remain) {
			if(count + 1 < min) {
				min = count + 1;
				found = true;
			}
			return;
		} else if (coins[cur] > remain) {
			while(cur >= 0 && coins(cur) > remain) {
				cur--;
			}
		}
		while(cur>=0) {
			helper(coins, cur, count+1, remain - coins(cur));
			cur--;
		}
	}
    int coinChange(vector<int>& coins, int amount) {
        found = false;
        min = math.MAX_INT;
        helper(coins, coins.size() - 1, 0, amount);
	    return found?min:-1;
    }
};