class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> tracker(26,0);
        int left = 0,right = 0,maxFreq = 0,ans = 0;
        int length = s.size();
        while(right<length)
        {
            tracker[s[right] - 'A']++;
            maxFreq = max(maxFreq,tracker[s[right]- 'A']);
            if(((right - left+1) - maxFreq) > k)
            {
                tracker[s[left] - 'A']--;
                left++;
            }
            ans = max(ans,(right-left+1));
            right++;
        }
        return ans;
    }
};