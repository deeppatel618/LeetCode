class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        for(int i:nums)
        {
            if(i>0)
                st.insert(i);
        }
        return st.size();
    }
};