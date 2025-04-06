class Solution {
public:
    // start exploring all the edges marked with O. These regions will not be converted into X . Along with this keep one ds to mark the visited nodes. 

    // Initialize the whole board to be filled with 0. Mark the nodes which are not to be converted at the end compare it with the main board.
    void dfs(vector<vector<char>>& board,vector<vector<int>>& marker,int row, int col){
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || marker[row][col] == 1|| board[row][col] == 'X') return;

        
        marker[row][col] = 1;
        dfs(board, marker, row+1,col);
        dfs(board, marker, row-1,col);
        dfs(board, marker, row,col+1);
        dfs(board, marker, row,col-1);
        

    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        // Initialize the whole board to be filled with 0. Mark the nodes which are not to be converted
        vector<vector<int>> marker(row,vector<int>(col,0));
        int mergeAble;
       
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O' && marker[i][0] == 0) dfs(board, marker, i, 0);
            if (board[i][col - 1] == 'O' && marker[i][col - 1] == 0) dfs(board, marker, i, col - 1);
        }
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O' && marker[0][j] == 0) dfs(board, marker, 0, j);
            if (board[row - 1][j] == 'O' && marker[row - 1][j] == 0) dfs(board, marker, row - 1, j);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && marker[i][j] == 0) { // region which has to be converted into X
                    board[i][j] = 'X';
                }
            }
        }
    }
    // O(M*N)
    //O(M*N)
};