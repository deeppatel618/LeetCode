class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        stack<char> st;
        for(int i = 0; i < num.size(); i++){
            while(!st.empty() && k > 0 && (st.top() - '0' > num[i]- '0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        if(st.empty()){return "0";}
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        while(!result.empty() && result.back() - '0' == 0){
            result.pop_back();
        }
        reverse(result.begin(),result.end());
        return result.size()>0?result:"0";
    }
};