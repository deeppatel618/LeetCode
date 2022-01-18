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
    int target=0;
    public boolean traversalSum(TreeNode root,int sum)
    {
        if(root== null) return false;
        sum+=root.val;
        if(root.left == null && root.right == null){
            return sum==target;
        }
        return traversalSum(root.left,sum) || traversalSum(root.right,sum);
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        target=targetSum;
        return traversalSum(root,0);
    }
}