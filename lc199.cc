/**
 * Definition for a binary tree Node->
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	void preOrderVisit(vector<int>& result, int level, TreeNode* currentNode) {
		if(currentNode == NULL) {
			return;
		}
		if(result.size() < level) {
			result.push_back(currentNode->val);
		}
		if(currentNode->right) {
			preOrderVisit(result, level + 1, currentNode->right);
		}
		if(currentNode->left) {
			preOrderVisit(result, level + 1, currentNode->left);
		}
	}
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		preOrderVisit(ret, 1, root);
		return ret;
    }
};