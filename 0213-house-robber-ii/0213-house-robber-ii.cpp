class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        vector<int> dp(n+1,-1);
        dp[0]= arr[0];
        for(int i=1; i<n-1;i++)
        {   
            int left= arr[i];
            if(i>1) left+=dp[i-2];
            int right = dp[i-1];
            dp[i] = max(left,right);
        }
        

        vector<int> dps(n+1,-1);
        dps[1]= arr[1];
        for(int i=2; i<n;i++)
        {   
            int left= arr[i];
            if(i>2) left+=dps[i-2];
            int right = dps[i-1];
            dps[i] = max(left,right);
        }
        return max(dps[n-1],dp[n-2]);
        }
};