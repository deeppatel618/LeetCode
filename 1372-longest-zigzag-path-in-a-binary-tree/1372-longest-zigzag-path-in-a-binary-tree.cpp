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
    int pathMaxLength = 0;
    void dfs(TreeNode* node, int left,int step)
    {
        if(node == NULL) return;
        pathMaxLength  = max(pathMaxLength,step);
        if(left)
        {
            dfs(node->left, 0, step+1);
            dfs(node->right, 1, 1);
            
        }
        else
        {
            dfs(node->right, 1, step+1);
            dfs(node->left, 0, 1);
        }
        
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,1,0);
        return pathMaxLength;
    }
};