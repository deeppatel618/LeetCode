class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sloc = 0;
        if(s.size()< 1) return true;
        for(int i = 0;i<t.size();i++)
        {
            if(s[sloc] == t[i])
            {
                sloc++;
            }
            if(sloc>=s.size()) return true;
        }
        return false;
    }
};