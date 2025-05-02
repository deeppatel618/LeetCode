class Solution {
public:
    int calc(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i-1] == text2[j-1])
            return dp[i][j] = 1 + calc(i - 1, j - 1, text1, text2, dp);
        else
            return dp[i][j] = max(calc(i - 1, j, text1, text2, dp),
                                  calc(i, j - 1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        for(int i = 0; i<=n1;i++) dp[i][0] = 0;
        for(int i = 0; i<=n2;i++) dp[0][i] = 0;

        for(int i = 1; i<=n1;i++){
            for(int j = 1; j<=n2;j++){
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n1][n2];
    }
};