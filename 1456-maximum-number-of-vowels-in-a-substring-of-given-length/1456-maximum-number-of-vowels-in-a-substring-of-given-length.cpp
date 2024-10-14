class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> mp={'a','e','i','o','u'};
        int ans = 0,count = 0;
        for(int i=0;i<k;i++)
        {
            count+=mp.count(s[i]);
        }
        ans = count;
        for(int i = k ; i<s.size();i++)
        {
            count+=mp.count(s[i]) - mp.count(s[i-k]);
            ans = max(count,ans);
        }
        return ans;
    }
};