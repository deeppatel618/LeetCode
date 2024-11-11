class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<pair<int,string>> freq;
        // calculate element and its frequency
        vector<string> ans;
        for(auto word:words)
        {
            mp[word]++;
        }

        for(auto &pr:mp)
        {
            freq.push_back({-(pr.second),(pr.first)});
        }
        make_heap(freq.begin(),freq.end(),greater<pair<int,string>>());
        for(int i = 0;i<k;i++)
        {
            pop_heap(freq.begin(),freq.end(),greater<pair<int,string>>());
            ans.push_back(freq.back().second);
            freq.pop_back();
        }
        return ans;
    }
};