class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i = 0; i<s.size();i++)
        {
            if(s[i] ==']')
            {
                string decodedString="";
                while(!st.empty() && st.top()!='[')
                {
                    decodedString += st.top();
                    st.pop();
                }
                
                st.pop();
                int num = 0;
                int base = 1;
                while(!st.empty() && isdigit(st.top()))
                {
                    num = num + (st.top() - '0')*base;
                    base*=10;
                    st.pop();
                }
                while(num!=0)
                {
                    for(int i = decodedString.size()-1; i>=0;i--)
                    {
                        st.push(decodedString[i]);
                    }
                    num--;
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans = "";
       while(!st.empty())
       {
        ans = st.top()+ans;
        st.pop();
       }
       return ans;
    }
};