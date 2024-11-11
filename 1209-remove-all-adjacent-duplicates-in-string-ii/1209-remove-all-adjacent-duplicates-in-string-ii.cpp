class Solution {
public:
    string removeDuplicates(string s, int k) {
     //Stack can also be used but using vector
        vector<pair<int,char>> count;
        for(int i =0; i<s.size();i++)
        {
            if(count.empty()|| s[i]!=count.back().second)
            {
                count.push_back({1,s[i]});
            }
            else
            {
                count.back().first++;
                if(count.back().first == k)
                {
                    count.pop_back();
                }
            }
        }
        string ans="";
        for(auto i: count)
        {
            ans += string(i.first,i.second);
        }
        return ans;
    }
};