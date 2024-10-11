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
        return right-left-1;
    }
 
    string longestPalindrome(string s) {
        int ans = -1,start = 0,end = 1;
        if(s.size() == 1) return s;
        for(int i = 0; i<s.size(); i++)
        {
            int len1 = countExpander(s,i,i);
            int len2 = countExpander(s,i,i+1);
            if(ans < len1)
            {
                start = i - len1/2;
                ans = len1;
            }
            if(ans<len2){
                start = i - ((len2/2) -1);
                ans = len2;
            }
        }
        // cout<<ans;
        return s.substr(start, ans);
    }
};