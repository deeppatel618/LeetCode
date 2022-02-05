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
    int tr;
    TreeNode t;
    void mirrorNode(TreeNode node){
        if(node == null) return;
        mirrorNode(node.left);
        mirrorNode(node.right);
        t = node.left;
        node.left = node.right;
        node.right = t;
        
    }
    public TreeNode invertTree(TreeNode root) {
        if(root == null ) return null ;
        mirrorNode(root);
        
        
        return root;
    }
    
}