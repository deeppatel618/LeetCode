class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int st1ptr = 0;
        int st2ptr = 0;
        while(st1ptr<word1.size() && st2ptr<word2.size())
        {
            ans += word1[st1ptr];
            st1ptr++;
            ans += word2[st2ptr];
            st2ptr++;
        }
        while(st1ptr<word1.size())
        {
            ans += word1[st1ptr];
            st1ptr++;
        }
        while(st2ptr<word2.size())
        {
            ans += word2[st2ptr];
            st2ptr++;
        }
        return ans;

    }
};