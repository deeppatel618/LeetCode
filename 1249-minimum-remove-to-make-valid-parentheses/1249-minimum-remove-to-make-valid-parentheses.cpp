class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string firstPassString ="";
        int balanceParentheses = 0;
        // To keep track of open bracket
        int openbrac=0;
        for(int i = 0;i< s.size();i++)
        {
            if(s[i] == '(' )
            {
                openbrac++;
                balanceParentheses++;
            }
            if(s[i] == ')')
            {
                // this closing bracket is invalid;
                if(balanceParentheses <= 0) continue; 
                balanceParentheses--;
            }
            firstPassString+=s[i];
        }
        string ans="";
        // second pass to remove the invalid/Extra opening bracket
        int openBracket = openbrac - balanceParentheses;
        for(int i = 0;i< firstPassString.size();i++)
        {
            if(firstPassString[i] == '(')
            {
                if(openBracket<=0) continue;
                openBracket--;
            }
            ans+=firstPassString[i];
        }
        return ans;
    }
};