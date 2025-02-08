class Solution {
public:
    vector<int> NextSmallerElement(vector<int> &arr)
    {
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i = arr.size()-1; i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            ans[i] = st.empty()? arr.size():st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> previousSmallerElement(vector<int> &arr)
    {
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i = 0 ; i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            ans[i] = st.empty()? -1:st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse = previousSmallerElement(arr);
        vector<int> nse = NextSmallerElement(arr);
    
        int result = 0;
        int mod = 1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            result= (result + ((i - pse[i]) *(nse[i] - i) * 1ll* arr[i])%mod)%mod;
        }
        
       return result; 
    }
};