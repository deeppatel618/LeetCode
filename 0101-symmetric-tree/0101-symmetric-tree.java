/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
      public boolean isSymmetric(TreeNode root) {

        return traversal(root.left,root.right);
    }
    public boolean traversal(TreeNode left,TreeNode right)
    {
        if(left == null && right == null) return true;
        if(left == null || right == null) return false;
        if(left.val != right.val ) return false;
        return traversal(left.left,right.right) && traversal(left.right,right.left);
    }
}