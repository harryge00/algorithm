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
private:
    TreeNode* tn;
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        traverse(root);
        return tn;
    }
    TreeNode* traverse(TreeNode* root) {
        if(!root) {
            // if(root) {
            //     cout<< root->val<<endl;
            // }
            return root;
        }
        if(!root->left) {
            if(!tn) {
                tn = root;
            }
            return root;
        }
        // root->left must not be empty
        // cout << "cur: "<< root->val <<endl;

        TreeNode* nr = traverse(root->left);
        if(root->right) {
            nr->left = traverse(root->right);
        } else {
            nr->left = NULL;
        }
        // cout << "after: "<< root->val <<endl;
        nr->right = root;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
};