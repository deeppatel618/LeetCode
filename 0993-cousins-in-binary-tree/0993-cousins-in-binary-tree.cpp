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
    TreeNode* xParentNode;
    TreeNode* yParentNode;
    int xdepth = -1;
    int ydepth = -1;
    void helper(TreeNode* root, int x, int y, int depth, TreeNode* parent)
    {
        if(root == nullptr) return;

        if(xdepth != -1)
            if(depth > xdepth) 
                return;
        
        if(ydepth != -1)
            if(depth > ydepth) 
                return;

        if(x == root->val)
        {
            xParentNode = parent;
            xdepth = depth;
        }
        else if(y == root->val)
        {
            yParentNode = parent;
            ydepth = depth;
        }
        helper(root->left,x,y,depth+1,root);
        helper(root->right,x,y,depth+1,root);

    }
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root,x,y,0,nullptr);
        return xParentNode != yParentNode && xdepth==ydepth;

    }
};