class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    st.push('#');
    for(char c:s)
    {
        if(c == '{' || c == '[' || c == '(')
        {
            st.push(c);
        }
        else if( ((c == '}' && st.top() == '{') || (c == ']' && st.top() == '[') || (c == ')' && st.top() == '(') )&& !st.empty())
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    if(st.top() == '#') return true;
    return false;
    }
};