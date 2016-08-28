/**
 * Definition for a binary tree node.

 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
	    if (root == null || root == p || root == q) return root;
	    TreeNode left = lowestCommonAncestor(root.left, p, q);
	    TreeNode right = lowestCommonAncestor(root.right, p, q);
	    return left == null ? right : right == null ? left : root;
	}
	private class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
      TreeNode(int x, TreeNode l, TreeNode r) { val = x; left = l; right = r; }
  	}
  	public static void main(String[] args) {

  		TreeNode root = new TreeNode(3);
  		root.left = new TreeNode(2, null, new TreeNode(-100));
  		root.right = new TreeNode(4, new TreeNode(-100), new TreeNode(5, null, new TreeNode(8)));
  		
  	}
}