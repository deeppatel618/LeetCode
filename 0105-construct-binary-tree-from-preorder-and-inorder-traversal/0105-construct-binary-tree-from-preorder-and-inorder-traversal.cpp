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
    int preOrderIndex = 0;
    unordered_map<int,int> inorderMap;
    TreeNode* arrayToTree(vector<int> &preorder, int leftIndex, int rightIndex)
    {
        if(leftIndex > rightIndex) return NULL; // No elements to construct the tree.

        int rootValue = preorder[preOrderIndex];
        TreeNode* root = new TreeNode(rootValue);
        preOrderIndex++;

        root->left = arrayToTree(preorder, leftIndex, inorderMap[root->val] -1);
        root->right = arrayToTree(preorder, inorderMap[root->val] + 1, rightIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0 ,preorder.size()-1);
    }
};