class Solution {
public:
    string countExpander(string s, int left, int right)
    {
        int counter = 0;
        while(left>=0 && right<s.size() && s[left] == s[right])
        {
            left--;
            right++;
            counter++;
        }
        return s.substr(left+1, right-left-1);
    }
 
    string longestPalindrome(string s) {
        string ans = "";
        int start = 0,end = 1;
        if(s.size() == 1) return s;
        for(int i = 0; i<s.size(); i++)
        {
            string str1 = countExpander(s,i,i);
            string str2 = countExpander(s,i,i+1);
            if(str1.size() > ans.size())
                ans = str1;
            if(str2.size() > ans.size())
                ans = str2;
            
        }
        return ans;
    }
};