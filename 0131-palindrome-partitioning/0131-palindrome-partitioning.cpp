class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substrings;
        // cout<<isPalindrome("abaa",0,3);
        partitioning(0,s,ans,substrings);
        return ans;
    }
    void partitioning(int index, string s, vector<vector<string>>& ans, vector<string>& substrings)
    {
        if(index == s.size())
        {
            ans.push_back(substrings);
            return;
        }
        for(int i=index; i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                substrings.push_back(s.substr(index,i-index+1));
                partitioning(i+1,s,ans,substrings);
                substrings.pop_back();
            }
        }

    }
    bool isPalindrome(string s, int start, int end)
    {
        while(start<end)
        {   
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};