class Solution {
public:
    int climbStairs(int n) {
        // return calculateSteps(0,n);

        vector<int> memo(n,0);
        return calculateStepsDp(0,n,memo);
    }

    // Brute Force solution 1
    int calculateSteps(int step, int n)
    {
        if(step > n ) return 0;
        if(step == n) return 1;

        return calculateSteps(step+1,n) + calculateSteps(step+2,n);
    }

    int calculateStepsDp(int step, int n,vector<int> &memo)
    {
        if(step > n ) return 0;
        if(step == n) return 1;
        if(memo[step]>0) return memo[step];

        memo[step] = calculateStepsDp(step+1,n,memo) + calculateStepsDp(step+2,n,memo);

        return memo[step];
    }
};