class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i = 0 ; i<strs[0].size();i++)
        {
            char curr = strs[0][i];
            // cout<<curr<<endl;
            for(int j = 1 ; j<strs.size();j++)
            {
                // cout<<strs[j][i]<<endl;
                if(strs[j].size() < i || strs[j][i] != curr)
                {
                    return ans;
                }
            }
            ans+=curr;
        }
        return ans;
    }
};