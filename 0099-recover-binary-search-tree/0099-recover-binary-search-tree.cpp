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
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
public:
    // At any point there are 2 possibilites. Adjacent nodes are to be swapped or non adjacent nodes are to be swapped.
    // If there is only one violation then swap first and middle but if there are 2 then swap first and last.
    void inorderTraversal(TreeNode* root)
    {
        if(root == nullptr) return;

        inorderTraversal(root->left);
        //visit 
        // Main logic goes here

        if(prev!=nullptr && root->val < prev->val) //Violation
        {
            if(first == nullptr)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        inorderTraversal(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorderTraversal(root);
        if(first && last) swap(first->val, last->val);
        else swap(first->val,middle->val);
    }
    // TC - O(N) visiting all nodes.
    // SC - O(N) stack space.
};