class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3) return s;
        string ans="";
        ans = s[0];
        for(int i = 1;i< s.size()-1;i++)
        {
            if( !(s[i-1] == s[i] && s[i] == s[i+1]))
            {
                ans+=s[i];
            }
            
        }
        ans +=s[s.size()-1];
        return ans;
    }
};