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
    
    private TreeNode lca = null;
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        dfs(root, p, q);
        return lca;
    }
    
    private boolean dfs(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return false;
        
        boolean isRoot = (root == p || root == q);
        boolean isInLeftTree = dfs(root.left, p, q);
        boolean isInRightTree = dfs(root.right, p, q);
        
        if (lca == null && ( (isRoot && (isInLeftTree || isInRightTree)) || (isInLeftTree && isInRightTree) )) {
            lca = root;
        }
        
        return isRoot || isInLeftTree || isInRightTree;
    }
}