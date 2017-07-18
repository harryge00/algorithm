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
public:
    bool isSame(TreeNode* left, TreeNode* right) {
        if(!left && !right) return 1;
        if(!left || !right) return 0;
        if(left->val != right->val) return 0;
        if(!isSame(left->right, right->left)) return 0;
        if(!isSame(left->left, right->right)) return 0;
        return 1;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSame(root->left, root->right);
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> left, right;
        left.push(root->left);
        right.push(root->right);
    	TreeNode* lh, *rh;
        while(left.size() && right.size()) {
        	lh = left.pop();
        	rh = right.pop();
        	if(!lh && !rh) {
        		continue;
        	}
        	if(!lh || !rh) return false;
        	if(lh->val != rh->val) return false;
        	left.push(lh->right);
        	left.push(lh->left);
        	right.push(lh->left);
        	right.push(lh->right);
        }
        return 1;
    }
};