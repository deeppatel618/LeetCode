class Solution {
public:

    int maxMoves(int row,int col, int prev,vector<vector<int>> &grid,int ans,int &maxSteps,vector<vector<int>> &dp)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || prev >= grid[row][col]) {
        return ans;
    }
    if(dp[row][col] !=-1)
        return dp[row][col];
    ans += 1;
 
    int upRight = maxMoves(row - 1, col + 1, grid[row][col], grid, ans, maxSteps,dp);
    int right = maxMoves(row, col + 1, grid[row][col], grid, ans, maxSteps,dp);
    int downRight = maxMoves(row + 1, col + 1, grid[row][col], grid, ans, maxSteps,dp);
    
    int maxMovesFromHere = max({upRight, right, downRight});
    maxSteps = max(maxSteps, maxMovesFromHere);
    dp[row][col] = maxSteps;
    return maxMovesFromHere;

    }
    int maxMoves(vector<vector<int>>& grid) {
        int maxSteps=-1;
        int ans=-1;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0; i<grid.size();i++)
        {
            maxSteps = -1;
            ans = max(maxMoves(i,0,-1,grid,0,maxSteps,dp)-1,ans);
            // ans = max(maxSteps,ans);
        }
        return ans;
    }
};