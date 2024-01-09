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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> myVector1;
        std::vector<int> myVector2;
        
        leafCreater(root1,myVector1);       
        leafCreater(root2,myVector2);
        
        

        return myVector1==myVector2;
    }
    void leafCreater(TreeNode* root,std::vector<int>& vector)
    {
        if(!root)
        {
            return;
        }
        if (root->left == NULL && root->right== NULL) {
            vector.push_back(root->val);
            
        }
        leafCreater(root->left,vector);
        leafCreater(root->right,vector);
    }
};