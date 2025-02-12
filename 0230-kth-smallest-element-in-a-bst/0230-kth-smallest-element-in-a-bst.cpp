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
    // Iterative approach for DFS. Explore left -> node -> right.
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(true)
        {
            while(root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            k--;
            if(k==0) return root->val;
            root = root->right;
        }
        return 0;

        // The time complexity for this code will be O(H+K). H is height of the tree. Every deletion take o(1) in stack, and we perform it for k elements. 

        // The space complexity for this is O(H). In worst case it can be O(N) when the tree is like linkedList.
    }
};