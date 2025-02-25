class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // remove the triplet if any of the value(at same index) is greater than target value. If we take that then the answer will be greater than target.
        // if the triplet is valid one. check if any of its value is equal to target.
        // If that's the case then add it to our set. At the end if it has 3 value then it means that all the places are filled and it is possible to form the answer.
        unordered_set<int> st;
        for(auto t:triplets){
            if(t[0]>target[0] || t[1]>target[1] || t[2]>target[2]){
                continue;
            }
            for(int i = 0; i<3 ;i++){
                if(t[i] == target[i]){
                    st.insert(i);
                }
            }
        }
        return st.size() == 3;
    }
    //O(n) O(1)
};