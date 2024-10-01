class Solution {
public:
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
                board[i][col] ='Q';
                leftDiagonal[i+col] = 1;
                rightDiagonal[(n-1) + (col - i)] = 1;
                row[i] =1;
                solve(col+1,n,board,ans,row,leftDiagonal,rightDiagonal);
                board[i][col] ='.';
                row[i]=0;
                leftDiagonal[i+col] = 0;
                rightDiagonal[(n-1) + (col - i)] = 0;

            }
        }

    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i< n; i++ )
        {
            board[i] = s;
        }
        vector<int> leftDiagonal(2*n-1,0), rightDiagonal(2*n-1,0),row(n,0);
        solve(0,n,board,ans,row,leftDiagonal,rightDiagonal);

        return ans;
    }
};