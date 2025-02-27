class TrieNode{
    public:
        unordered_map<char,TrieNode*> children;
        string word;
        TrieNode():word(""){}
};
class Solution {
    vector<string> result;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(string &word:words){
            TrieNode *curr = root;
            for(char ch:word){
                if(curr->children.find(ch) == curr->children.end()){
                    TrieNode *newNode = new TrieNode();
                    curr->children[ch] = newNode;
                }
                curr = curr->children[ch];
            }
            curr->word = word;
        }

        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                if(root->children.find(board[row][col]) != root->children.end()){
                    backtracking(board,row,col,root);
                }
            }
        }
        return result;
    }
    void backtracking(vector<vector<char>> &board, int row, int col, TrieNode *node){
        char letter = board[row][col];
        TrieNode *currNode = node->children[letter];

        if(currNode->word != ""){
            result.push_back(currNode->word);
            currNode->word = "";//Ignore duplicates. Clear this so we do not encounter this again.
        }

        board[row][col] = '#';

        int rowOffset[] = {-1,0,1,0};
        int colOffset[] = {0,-1,0,1};
        for(int i = 0; i < 4; i++){
            int newRow = rowOffset[i]+row;
            int newCol = colOffset[i]+col;
            if(newRow < 0 || newRow >= board.size() || newCol<0 || newCol>= board[0].size()){
                continue;
            }
            if(currNode->children.find(board[newRow][newCol]) != currNode->children.end()){
                backtracking(board,newRow,newCol,currNode);
            }
        }
         board[row][col]=letter;
    }
};