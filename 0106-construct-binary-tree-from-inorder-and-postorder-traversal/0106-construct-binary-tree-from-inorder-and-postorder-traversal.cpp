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
    TreeNode* conversion(vector<int>& inorder , int is,int ie, vector<int>& postorder,int ps,int pe, map<int,int>& hm)
    {
        if(ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode();
        root->val = postorder[pe];
        int rootNodeloc = hm[postorder[pe]];
        int nodesleft = rootNodeloc-is;

        root->left = conversion(inorder,is, rootNodeloc-1, postorder, ps, ps+nodesleft-1,hm);
        root->right = conversion(inorder,rootNodeloc+1,ie, postorder, ps+nodesleft, pe-1,hm);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        if(inorder.size() != postorder.size()) return NULL;
        for(int i = 0; i < inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        return conversion(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};