class Solution {
public:
    vector<int> countFreq(string s)
    {
        vector<int> ans(26,0);
        for(char c:s){
            ans[c-'a']++;
        }
        return ans;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> word2Max(26,0);
        for(auto s:words2)
        {
            vector<int> charCounts = countFreq(s);
            for(int i =0; i<26;i++)
            {
                word2Max[i] = max(word2Max[i],charCounts[i]);
            }
        }
        vector<string> ans;
        for(auto s:words1){
            bool flag = true;
            for(int i =0; i<26;i++)
            {
                if(word2Max[i]!=0){
                    if(count(s.begin(),s.end(),char(i+'a')) < word2Max[i]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                ans.push_back(s);
        }
        return ans;
    }
};