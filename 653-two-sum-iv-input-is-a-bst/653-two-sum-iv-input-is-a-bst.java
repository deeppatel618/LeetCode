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
 HashSet<Integer> a= new HashSet<>();
    public boolean findTarget(TreeNode root, int k) {
        traversal(root);
        for (int i:
             a) {
            if( k/2!=i &&  a.contains(k- i ) )
            {
                return true;
            }
        }
        return false;
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