class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> tracker(256,-1);
        int left = 0;
        int right = 0;
        int ans=0;
        while(right < s.size())
        {
            if(tracker[s[right]] != -1)
            {
                left = max(tracker[s[right]] + 1,left);    
            }
            tracker[s[right]] = right;
            ans = max(right-left+1,ans);
            right++;
        }
        return ans;
    }
};