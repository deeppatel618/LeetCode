/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // We are implementing level order traversal through which the string will be created.
    // It is little different than the LOT, where we only add the node if it is not null but here we add the node and if its null we will mark it as #.
    // For example 1 the str would be "1,2,3,#,#,4,5,#,#,#,#,"
    string serialize(TreeNode* root) {

        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            
            if (curNode == NULL) 
                s.append("#,");
            else 
                s.append(to_string(curNode->val) + ',');

            if (curNode != NULL) {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    // We the deserialize we will use queue where we will take the first node and add it to the queue.
    // For each element in the queue, we will pop it and first look for left child, which will be the next element in the string.
    // If it is not null then insert it into the queue
    // Repeat for right.
    // It goes on until the tree is covered.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#") {
            node->left = NULL;
        } else {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if (str == "#") {
            node->right = NULL;
        } else {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
    }
    // O(n)- traversing through the tree once
    // o(n) - using queue.
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));