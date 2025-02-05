class Solution {
public:
    // Backtracking
    bool isValidSudoku(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == c)  return false; // Checking if the character appears at any other place in the same row.

            if(board[i][col] == c)  return false; // for column.
            

            // Check for each 3*3 box. Lets first find out which box are we in at the moment.
            int rowBox = row/3;
            int colBox = col/3;

            int startRowIndexOfBox = 3 * rowBox;
            int startColIndexOfBox = 3 * colBox;
            if(board[startRowIndexOfBox + i/3][startColIndexOfBox + i%3] == c)  return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0; i<board.size();i++)
        {
            for(int j=0; j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c<='9';c++)
                    {
                        if(isValidSudoku(board,i,j,c))
                        {
                            board[i][j] = c;
                            if(solve(board) == true) 
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }


};