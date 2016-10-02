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
    bool helper(TreeNode *root, int *depth) {
      if(!root) {
        *depth = 0;
        return true;
      }

      if(!helper(root->left, depth)) {
        return false;
      }
      int tmp = *depth;
      if(!helper(root->right, depth)) {
        return false;
      }
      if(abs(*depth -tmp) > 1) {
        return false;
      }
      *depth = 1 + max(tmp, *depth);
      return true;
    }
    bool isBalanced(TreeNode* root) {
      int x = 0;
      return helper(root, &x);
    }
};
