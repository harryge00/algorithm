class Solution {
private:
	vector<vector<int>> ret;
	void search(vector<int>& candidates, vector<int> one, int cur, int remain) {
		for(int i = cur; i < candidates.size(); i++) {
			if(candidates[i] == remain) {
				one.push_back(candidates[i]);
				ret.push_back(one);
				return;
			} else if (candidates[i] > remain) {
				return;
			} else {
				one.push_back(candidates[i]);
				search(candidates, one, i + 1, remain - candidates[i]);
				one.pop_back();
				while(i + 1 < candidates.size() && candidates[i + 1] == candidates[i]) {
					i++;
				}
			}
		}
	}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> one;
        search(candidates, one, 0, target);
        return ret;
    }
};
vector<vector<int>> ret(n, vector<int> (n));