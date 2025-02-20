class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& grid, int row, int col, int &count, int m ,int n)
    {
        if( row>=m || col>=n || row<0 || col < 0 || grid[row][col] != 1) return;
        grid[row][col] = '#';
        count +=1;
        ans = max(count,ans);
        dfs(grid,row+1,col,count,m,n);
        dfs(grid,row,col+1,count,m,n);
        dfs(grid,row-1,col,count,m,n);
        dfs(grid,row,col-1,count,m,n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j<n;j++)
            {
                int count = 0;
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,count,m,n);
                }
                // cout<<count<<endl;
            }
        }
        return ans;
    }
};