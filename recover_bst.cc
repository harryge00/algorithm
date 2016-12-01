/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	TreeNode* wrongElem1, *last, *possible;
	void dfs(TreeNode* node) {
		if(!node) return;
		if(wrongElem1 && !last) return; //means the two elements have been swapped.
		dfs(node->left);
		if(last && node->val < last->val) {
			if(!wrongElem1) {
				wrongElem1 = last;
				possible = node;
			} else {
				int tmp = wrongElem1->val;
				wrongElem1->val = node->val;
				node->val = tmp;
				last = NULL;
				return;
			}
		}
		last = node;
		dfs(node->right);
	}
public:
    void recoverTree(TreeNode* root) {
    	last=NULL, wrongElem1=NULL;
        dfs(root);
        if(last) {
        	int tmp = wrongElem1->val;
			wrongElem1->val = possible->val;
			possible->val = tmp;
        }
    }
};