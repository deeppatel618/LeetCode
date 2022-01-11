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
    List<List<Integer>> a=new ArrayList<>();
    int max=0;
    public int maxDepth(TreeNode root) {
        int index=0;
        traversal(root,index);
        return max;
        
    }
    public void traversal(TreeNode rt,int index)
    {
        if(rt == null)
            return;
        if(a.size()<index+1) {
             a.add(new ArrayList<>());
        }
        a.get(index).add(rt.val);
        index++;
        if(max<index) max=index;
        traversal(rt.left,index);
        traversal(rt.right,index--);
        
    }
}