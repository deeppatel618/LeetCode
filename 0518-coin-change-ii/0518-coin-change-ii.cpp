class Solution {
public:
    int f(int index, int total,vector<int>& coins,vector<vector<int>>& dp){
        if(index == 0){
            if(total % coins[index] == 0)
                return 1;
            return 0;

        }
        if(dp[index][total] != -1) return dp[index][total];
        int notPick = f(index -1 , total,coins,dp);
        int pick = 0;
        if(coins[index] <= total){
            pick = f(index, total - coins[index], coins,dp);
        }
        return dp[index][total] = notPick+pick;
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1, -1));
        int result = f(coins.size()-1,amount,coins,dp);
        return result;
    }
};