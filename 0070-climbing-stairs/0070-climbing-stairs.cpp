class Solution {
public:
    
   
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
        return countStep(n,dp);
    }
    
    int countStep(int steps,vector<int> &dp)
    {
        if(steps == 0) return 1;
        if(steps == 1) return 1;
        if(dp[steps] != -1)
        {
            return dp[steps];
        }
        
        return dp[steps] = countStep(steps-1,dp)+countStep(steps-2,dp);
    }
};