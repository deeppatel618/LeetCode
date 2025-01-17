class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window with vector to keep track of last location of particular char.
        vector<int> mp(256,-1);
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while(right< s.size())
        {
            //already seen this character before
            if(mp[s[right]] != -1)
            {
                left = max(left, mp[s[right]] + 1 );
            }
            //update char location.
            mp[s[right]] = right;
            maxLen = max(right-left+1,maxLen);
            right++;
        }
        return maxLen;

    }
};