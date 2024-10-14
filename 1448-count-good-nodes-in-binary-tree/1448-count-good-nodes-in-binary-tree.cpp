/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int currMax)
    {
        
        if(node == NULL) return 0;

        currMax = max(currMax,node->val);
        int ans = 0;
        ans+=dfs(node->left,currMax);
        ans+=dfs(node->right,currMax);
        if(node->val>=currMax)
            return ans+1;
        return ans;
        
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};