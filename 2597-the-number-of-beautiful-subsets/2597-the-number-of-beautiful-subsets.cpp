class Solution {
public:
    vector<int>* nums;
    int difference=0;
    unordered_map<int,int> freqMap;
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        this->nums = &nums;
        difference  = k;
        return subsetCounter(0) - 1;
    }
    int subsetCounter(int i)
    {
        if(i == (*nums).size())
        {
            return 1;
        }
        int totalCount = subsetCounter(i+1);

        if(!freqMap[(*nums)[i] - difference])
        {
            freqMap[(*nums)[i]]++;
            totalCount += subsetCounter(i+1);
            freqMap[(*nums)[i]]--;
        }
        return totalCount;
    }
};