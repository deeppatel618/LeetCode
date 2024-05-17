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
    int dfs(TreeNode* root,int target)
    {
        if(root == nullptr)
        {
            return 0;
        }
        
        int left = dfs(root->left,target);
        if(left == -1)
            root->left = nullptr;
        int right = dfs(root->right,target);
        if(right == -1)
            root->right = nullptr;
        if(root->val == target && root->right ==nullptr && root->left == nullptr)
        {
            return -1;
        }
        return 0;

    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        int temp = dfs(root,target);
        if(temp == -1) // last node is also the target.
        {
            root = nullptr;
        }
        return root;
    }
};