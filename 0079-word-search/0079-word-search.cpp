class Solution {
public:
    bool search(vector<vector<char>> &board, string word,int k,int i,int j)
    {
        if(k == word.size()) return true;
        int row = board.size();
        int col = board[0].size();

        if(i<0 || j<0 || i>=row || j>=col || board[i][j] == '#' || board[i][j]!= word[k])
        {
            return false;
        }
        char ch =  board[i][j];

        board[i][j] = '#';
        bool up = search(board,word,k+1,i-1,j);
        bool down = search(board,word,k+1,i+1,j);
        bool right = search(board,word,k+1,i,j-1);
        bool left = search(board,word,k+1,i,j+1);
        board[i][j] = ch;

        return up || down || right || left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size();i++)
        {
            for(int j = 0; j < board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    if(search(board,word,0,i,j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};