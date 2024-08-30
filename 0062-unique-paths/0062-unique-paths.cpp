class Solution {
public:
    int maxM,maxN;
    long long pathTracker(int i, int j,vector<vector<int>> &dp) {
        if (i == maxM - 1 && j == maxN - 1) {
            return 1; // Return 1 when reaching the end of the grid
        }
        if (i >= maxM || j >= maxN) {
            return 0; 
        }
        if(dp[i][j] != -1) return dp[i][j];
    
        else return dp[i][j] =pathTracker(i + 1, j,dp) + pathTracker(i, j + 1,dp);
    }
    long long totalNumberOfPathFinder(int n, int r)
    {
        long long counter =1;
        for(int i = 0; i < r; i++ )
        {
            counter *= n;
            counter/=i+1;
            n--;
        }
        return counter;
    }
    int uniquePaths(int m, int n) {
        maxM = m;
        maxN = n;
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return totalNumberOfPathFinder(m+n-2,n-1<m-1?n-1:m-1);
    }
};