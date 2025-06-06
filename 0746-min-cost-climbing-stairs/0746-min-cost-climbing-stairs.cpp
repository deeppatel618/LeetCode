class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i< cost.size()+1; i++){
            dp[i] = min(dp[i-1] +cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
    // recursive with memo
    int minCost(int i, vector<int> &cost,vector<int> &dp){
        if(i == 0 || i == 1) return 0;
        if(dp[i]!=-1) return dp[i];
        int one = minCost(i-1,cost,dp) +cost[i-1]; // Cost till i-1 + cost of i-1
        int two = minCost(i-2,cost,dp) +cost[i-2];

        return dp[i] = min(one, two);
         
    }

};