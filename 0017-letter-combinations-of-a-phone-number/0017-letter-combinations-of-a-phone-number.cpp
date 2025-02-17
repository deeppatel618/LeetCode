class Solution {
public:
   vector<string> phone = {
    "",    "",    "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"};
    // Try every combination using backtracking.
    void backtrac(int index, string digits,string curr,vector<string> &ans)
    {
        if(index == digits.size()) {
            ans.push_back(curr);
            return; 
        }
        for(char c:phone[digits[index] - '0'])
        {
            curr.push_back(c);
            backtrac(index+1,digits,curr,ans);
            curr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.empty())
            backtrac(0,digits,"",ans);
        return ans;
    }

    //O(N.4^N) as for the 7th and 9th digit there are 4 digits.
    //O(N) recursive stack can go upto depth N.
};