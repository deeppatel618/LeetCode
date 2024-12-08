class Solution {
public:
    /* Recursive approach - 1
    int rob(int ind , vector<int> &nums)
    {
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        int pick = nums[ind] + rob(ind-2,nums);
        int notPick =  rob(ind-1,nums);
        return max(pick,notPick);
    }
    */

    /* Recursive approach - 2 
    int rob(int ind , vector<int> &nums,vector<int> &dp) 
    {
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + rob(ind-2,nums,dp);
        int notPick =  rob(ind-1,nums,dp);
        return dp[ind] = max(pick,notPick);
    }
    */
    /* At any point we only require 2 elements sum. index -1 or index -2. This will help me space optimization
    */
    int rob(vector<int>& nums) {
        int prev = nums[0]; // index 0
        int prev2 = 0; // for now it is index -1

        int pick,notPick,curr;
        for(int i = 1;i<nums.size() ; i++)
        {
            pick = nums[i]+prev2;
            notPick = prev;
            curr = max(pick,notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};