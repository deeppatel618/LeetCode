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
    TreeNode* convertIntoGraph(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap, int start)
    {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode *targetNode = nullptr;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop(); 
            if(curr->val == start) targetNode = curr;

            if(curr->left)
            {
                q.push(curr->left);
                parentMap[curr->left] = curr;
            }
            if(curr->right)
            {
                q.push(curr->right);
                parentMap[curr->right] = curr;
            }

        }
        return targetNode;

    }

    int findMaxDistance(unordered_map<TreeNode*, TreeNode*> parentMap, TreeNode* target)
    {
        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, int> visited;
        visited[target] = 1; 

        int time = 0;
        while(!q.empty())
        {
            int currSize = q.size();
            int flow = 0;
            for(int i = 0; i < currSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) // check if it has left node
                {
                    flow = 1;
                    visited[node->left] = 1;
                    q.push(node->left);
                }

                if(node->right && !visited[node->right]) // check if it has right node
                {
                    flow = 1;
                    visited[node->right] = 1;
                    q.push(node->right);
                }

                if(parentMap[node] && !visited[parentMap[node]])//// check if it has left node
                {
                    flow = 1;
                    visited[parentMap[node]] = 1;
                    q.push(parentMap[node]);
                }
                
            }
            if(flow) time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode *targetNode = convertIntoGraph(root, parentMap,start);

        return findMaxDistance(parentMap,targetNode);
    }
};