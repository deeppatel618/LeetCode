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
    void levelOrderTraversal(TreeNode* root,vector<vector<int>> &ans,int index)
    {
        if(root == NULL) return;
        if(ans.size() < index) 
        {
            ans.push_back({});
        }
        ans[index-1].push_back(root->val);
        index++;
        levelOrderTraversal(root->left,ans,index);
        levelOrderTraversal(root->right,ans,index);
        index--;
        

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrderTraversal(root,ans,1);
        return ans;
    }
};