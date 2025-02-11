/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Recursive approach 1


    // TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    // {
    //     if(root == NULL) return NULL;
    //     int curr = root->val;
    //     if(curr < p->val && curr < q->val)
    //     {
    //         return lca(root->right,p,q);
    //     }
    //     if(curr > p->val && curr > q->val)
    //     {
    //         return lca(root->left,p,q);
    //     }
    //     return root;

    // }

    // Iterative approach 2 (Same logic)
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL) return NULL;
        TreeNode* node = root;
        while(node!=nullptr)
        {
            int curr = node->val;
            if(curr < p->val && curr < q->val)
            {
                node = node->right;
            }
            else if(curr > p->val && curr > q->val)
            {
                node = node->left;
            }
            else
            {
                return node;
            }   
        }
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)    
    {
        return lca(root,p,q);
    }
};