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
    List<Integer> a=new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
        traversal(root);
        return a;
    }
    public void traversal(TreeNode rt)
    {
            if(rt == null)
                return;
            a.add(rt.val);
            traversal(rt.left);
            traversal(rt.right);
    }
}