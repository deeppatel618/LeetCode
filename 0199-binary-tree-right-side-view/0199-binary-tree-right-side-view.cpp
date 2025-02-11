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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        vector<int> rightSide;
        q.push(root);

        while(!q.empty())
        {
            int currSize = q.size();
            for(int i = 0 ;i<currSize;i++)
            {
                TreeNode* currNode = q.front();
                q.pop();

                if(i == currSize -1)
                {
                    rightSide.push_back(currNode->val);
                }

                if(currNode->left != nullptr)
                {
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr)
                {
                    q.push(currNode->right);
                }
            }
        }
        return rightSide;
    }
};