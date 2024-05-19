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
    int moves = 0;
    int calculateMoves(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int leftCounter = calculateMoves(root->left);
        int rightCounter = calculateMoves(root->right);
        moves = moves + abs(leftCounter) + abs(rightCounter);
        return root->val - 1 +leftCounter+ rightCounter;


    }
    int distributeCoins(TreeNode* root) {
        calculateMoves(root);
        return moves;
    }
};