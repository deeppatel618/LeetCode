class Solution {
public:
    bool helper(int i, int j, string &pattern, string &text,vector<vector<int>> &dp)
    {
        if(i<0 && j<0) return true;// Both the strings are exhausted.
        if(i<0 && j>=0) return false; // pattern is exhausted
        if(j<0 && i>= 0) // if text is exhausted and there are '*'s in the pattern  
        {
            for(int ii = 0; ii<=i ;ii++)
            {
                if(pattern[ii] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(pattern[i] == text[j] || pattern[i] =='?')
        {
            return dp[i][j] = helper(i-1,j-1,pattern,text,dp);
        }
        if(pattern[i] == '*')
        {
            return dp[i][j] = helper(i-1,j,pattern,text,dp) | helper(i,j-1,pattern,text,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int j = s.size()-1;
        int i = p.size()-1;
        vector<vector<int>> dp(i+1,vector<int>(j+1,-1));
        return helper(i,j,p,s,dp);
    }
};