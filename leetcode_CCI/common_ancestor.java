/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Stack<TreeNode> pAncestors = new Stack<TreeNode> ();
        Stack<TreeNode> qAncestors = new Stack<TreeNode> ();
        boolean resP = findChild(root, p, pAncestors);
        if(!resP) return null;
        boolean resQ = findChild(root, q, qAncestors);
        if(!resQ) return null;
        TreeNode pre = null, cur1 = pAncestors.pop(), cur2 = qAncestors.pop();
        while(!pAncestors.empty() && !qAncestors.empty()) {
        	if(cur1 != cur2 )	return pre;
        	pre = cur1;
        	cur1 = pAncestors.pop();
        	cur2 = qAncestors.pop();
        }
        return cur1 == cur2 ? cur1 : pre;
    }
    private boolean findChild(TreeNode a, TreeNode child, Stack<TreeNode> st) {
        if(a == null) return false;
        if(a.val == child.val) {
        	st.add(a); 
        	return true;
        }

        boolean leftRes = findChild(a.left, child, st);
        if(leftRes)	{
        	st.add(a);
        	return true;
        }
        boolean rightRes = findChild(a.right, child, st);
        if(rightRes) {
        	st.add(a);
        	return true;
        }
        return false;
    }
}

