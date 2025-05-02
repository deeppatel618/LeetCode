class Solution {
public: 
    // Recursive solution with memoization
    int f(int index, int total,vector<int>& coins,vector<vector<int>>& dp){
        if(index == 0){
            if(total % coins[index] == 0)
                return total/coins[index];
            return 1e9;

        }
        if(dp[index][total] != -1) return dp[index][total];
        int notPick = 0 + f(index -1 , total,coins,dp);
        int pick = 1e9;
        if(coins[index] <= total){
            pick = 1 + f(index, total - coins[index], coins,dp);
        }
        return dp[index][total] = min(notPick,pick);
        
    }

    int coinChange(vector<int>& coins, int amount) {
    
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1, -1));
        int result = f(coins.size()-1,amount,coins,dp);
        return result>= 1e9?-1:result;
        
    }
};