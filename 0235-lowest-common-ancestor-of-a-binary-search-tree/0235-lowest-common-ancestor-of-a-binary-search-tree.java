/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    TreeNode lastAncestor;
    TreeNode p, q;
    public void getOrder(TreeNode t){
        if (t==null) return;
        if(p.val<t.val && q.val<t.val) {
            lastAncestor = t;
            getOrder(t.left);
        }
        else if(p.val>t.val && q.val>t.val) {
            lastAncestor = t;
            getOrder(t.right);
        }
        else{
            lastAncestor = t;
            return;
        }

    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        this.p = p;
        this.q = q;
        getOrder(root);
        return lastAncestor;
    }
}