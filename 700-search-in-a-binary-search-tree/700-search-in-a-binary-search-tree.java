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
    TreeNode a=new TreeNode();
    public TreeNode searchBST(TreeNode root, int val) {
        target=val;
        return Search(root);
    }
    public TreeNode Search(TreeNode root){
        if(root==null) return null;
        System.out.println(root.val);
        if(root.val == target)
        {
                return root;
        }
        if(root.val < target) return Search(root.right);
        else return Search(root.left);
        
    }
}