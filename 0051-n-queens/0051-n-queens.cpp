class Solution {
public:
    // Logic is to consider first columns try all the possible ways to keep the queen there and then move to next column.
    // While selecting one position marked it and move to next column. Remove the mark while backtracking.

    // To avoid extra data structure or a whole board. we can use 3 vectors row, leftdia, rightdia, to keep track of placed queens.

    // Left diagonal \ can be represented using (row+col)
    // right diagonal / can be represented using (n-1 + col - row)
    
    void solve(int col,int n, vector<string> &board, vector<vector<string>> &ans,vector<int> &row,vector<int> &leftDiagonal, vector<int> &rightDiagonal)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int i =0; i<n; i++)
        {
            if(row[i] == 0 && leftDiagonal[i+col] == 0 && rightDiagonal[n-1 + col-i] == 0)
            {
                // Place the queen and fill the required spaces.
                board[i][col] ='Q';
                leftDiagonal[i+col] = 1;
                rightDiagonal[(n-1) + (col - i)] = 1;
                row[i] =1;

                solve(col+1,n,board,ans,row,leftDiagonal,rightDiagonal); // Move to next column considering that queen in the current column is at its correct placement.

                // Backtrack. Remove all filled places.
                board[i][col] ='.';
                row[i]=0;
                leftDiagonal[i+col] = 0;
                rightDiagonal[(n-1) + (col - i)] = 0;

            }
        }

    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        // Each row in the board is represented as string with all the values '.'
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i< n; i++ )
        {
            board[i] = s;
        }

        //Initialize 3 vectors.
        vector<int> leftDiagonal(2*n-1,0), rightDiagonal(2*n-1,0),row(n,0);
        
        solve(0,n,board,ans,row,leftDiagonal,rightDiagonal);

        return ans;
    }
    // TC - O(N!) - For the 1st queen we would have n options but for 2nd queen we would have n-2 as 1 row and at min another row will be removed(diagonal) and goes on
    // SC - O(N^2) - we are using vectors also the calls would consume recursive stack space. Not including the answer space.

};