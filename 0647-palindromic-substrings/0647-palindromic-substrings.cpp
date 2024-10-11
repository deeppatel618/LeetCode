class Solution {
public:
    int countExpander(string s, int left, int right)
    {
        int counter = 0;
        while(left>=0 && right<s.size() && s[left] == s[right])
        {
            left--;
            right++;
            counter++;
        }
        return counter;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++)
        {
            ans+=countExpander(s,i,i);
            ans+=countExpander(s,i,i+1);
        }
        return ans;
    }
};