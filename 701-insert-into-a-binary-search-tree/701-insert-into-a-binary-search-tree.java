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
    TreeNode a =new TreeNode();
    TreeNode ans;
    public TreeNode insertIntoBST(TreeNode root, int val) {
        target=val;
        a.val = val;
        ans = root;
        if(root == null )
            ans = a;
        else
            traversal(root);
        return ans;
    }
    public void traversal(TreeNode root)
    {
    
            if(root.val>target)
            {
                if(root.left==null){
                    root.left=a;
                    return;
                }
                else 
                    traversal(root.left);
            }
            else
            {
                if(root.right==null){
                    root.right=a;
                    return ;
                }
                else 
                    traversal(root.right);
            }
    }
}