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
   public List<Integer> inorderTraversal(TreeNode root) {
        traversal(root);
        return a;
    }
    public void traversal(TreeNode rt)
    {
            if(rt == null)
                return;
            traversal(rt.left);
            a.add(rt.val);
            traversal(rt.right);
    }

}