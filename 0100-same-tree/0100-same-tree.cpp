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
    bool identicalTree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL) return true;
        if((p==NULL || q == NULL) || p->val != q->val) return false;
        if( identicalTree(p->left,q->left) &&
        identicalTree(p->right,q->right))
        {
            return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return identicalTree(p,q);
    }
};