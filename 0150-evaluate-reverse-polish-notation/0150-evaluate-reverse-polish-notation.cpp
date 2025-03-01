class Solution {
public:
    int evalRPN(vector<string>& tokes) {
        stack<int> st;
        for(int i = 0; i<tokes.size();i++){
            if(tokes[i] == "+"|| tokes[i] == "-"|| tokes[i] == "/"|| tokes[i] == "*"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(tokes[i] == "+"){ st.push(a+b);}
                if(tokes[i] == "-"){ st.push(a-b);}
                if(tokes[i] == "/"){ st.push(a/b);}
                if(tokes[i] == "*"){ st.push(a*b);}
            }
            else{
                st.push(stoi(tokes[i]));
            }
        }
        return st.top();
    }
};