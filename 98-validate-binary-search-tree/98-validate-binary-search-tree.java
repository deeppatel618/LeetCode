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
    public boolean isValidBST(TreeNode root) {
        traversal(root);
        if(a.size()==1) return true;
        else {
            for(int i=0;i<a.size()-1;i++)
            {
                // System.out.println(a.get(i));
                if(a.get(i)>=a.get(i+1)) return false;
            }
        
        }
        return true;
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