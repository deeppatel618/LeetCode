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
    // Traverse through each node in the main tree and check for subtree.
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if(p == nullptr and q == nullptr ) return true;
        if(p == nullptr or q == nullptr ) return false;
        if(p->val == q->val)
        {
            return isSame(p->left, q->left) && isSame(p->right, q->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot == nullptr) return true;
        if(root == nullptr) return false;

        if(isSame(root,subRoot))
            return true;
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

    }
    // o(m*n) // M is nodes in main tree and n is nodes in the subtree. In worstcase when all the values are same we need to look for subtree in every node
    // O(m+n);
};