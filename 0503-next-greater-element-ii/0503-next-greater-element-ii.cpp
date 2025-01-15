class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Same logic as part 1 but just double the array.
        // remove element from the stack which are smaller than the current element. Update the ans when we are in len of orignial nums, that is nums.size(); 
        stack<int> st;
        int len = nums.size();
        vector<int> ans(len);
        for(int i = (2*len)-1; i>=0;i--){
            while(!st.empty() && st.top() <= nums[i % len]){
                st.pop();
            }
            if(i<len){
                ans[i] = st.empty() ? -1: st.top();
            }
            st.push(nums[i%len]);
        }
        return ans;
    }
};