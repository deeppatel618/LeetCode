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
    TreeNode* ans = NULL;
    bool recruseTree(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return false;

        int right = recruseTree(root->right, p ,q)?1:0;
        int left = recruseTree(root->left, p ,q) ?1:0;
        int isRoot = (root == p || root == q)?1:0;

        if(isRoot+right+left>1){
            ans = root;
        }
        return (isRoot + right + left)>0;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recruseTree(root,p,q);
        return ans;
    }
};