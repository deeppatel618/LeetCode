class Solution {
public:
    void dfsBracket(vector<string> &ans, int n, int left, int right,string currString)
    {
        if(currString.size() == 2*n)
        {
            ans.push_back(currString);
            return;
        }
        if(left<n)
        {
            currString+='(';
            dfsBracket(ans,n,left+1,right,currString);
            currString.pop_back();

        }
        if(left>right)
        {
            currString+=')';
            dfsBracket(ans,n,left,right+1,currString);
            currString.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfsBracket(ans,n,0,0,"");
        return ans;
    }
};