class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> count;
        for(auto i:arr)
        {
            if((count.find(2*i) !=count.end()) || (i%2==0 && count.find(i/2) !=count.end()))
            {
                return true;
            }
            count.insert(i);
        }
        return false;
    }
};