class Solution {
public:
    int maxDepth(string s) {
        int curr = 0;
        int ans =0;
        for(char i:s)
        {
            if(i == '(')
            {
                curr+=1;
                ans= max(ans,curr);
            }
            else if(i == ')')
            {
                curr-=1;
            }
        }
        return ans;  
    }
};