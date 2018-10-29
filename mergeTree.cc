#include <iostream>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
  if(t1 == NULL){
    return t2;
  }
  if(t2 == NULL) {
    return t1;
  }
  TreeNode* t3 = new TreeNode(t1->val + t2->val);
  t3->left = mergeTrees(t1->left, t2->left);
  t3->right = mergeTrees(t1->right, t2->right);
  return t3;
};

int main ()
{
  mergeTrees(NULL, NULL);
  return 0;
}
