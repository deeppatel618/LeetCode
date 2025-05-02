class Solution {
public:
    // Recursive
    int n = 0;
    int f(int index, int buy, vector<int> &prices){
        if(index >= n) return 0;
        //Buy the stock
        if(buy == 1){
            // If buying add the prices and change buy to 0 indicating sell
            return max(-prices[index] + f(index+1,0,prices), 0 + f(index+1,1,prices));
        }
        // Sell
        return max(prices[index] + f(index+2,1,prices) , 0 + f(index+1,0,prices));
    }

    // Memoization
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(3,0));
        for(int i = n - 1; i>=0 ;i--){
            for(int j = 0; j<=1; j++){
                if(j == 1)
                    dp[i][j] = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
                else
                    dp[i][j] = max(prices[i] + dp[i+2][1], 0 + dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};