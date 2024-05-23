class Solution {
public:
  
    int difference=0;
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> freqMap;
        difference  = k;
        return subsetCounter(0,freqMap,k,nums) - 1;
    }
    int subsetCounter(int i, unordered_map<int,int> &freqMap,int difference, vector<int> &nums)
    {
        if(i == nums.size())
        {
            return 1;
        }
        int totalCount = subsetCounter(i+1,freqMap,difference,nums);

        if(!freqMap[nums[i] - difference])
        {
            freqMap[nums[i]]++;
            totalCount += subsetCounter(i+1,freqMap,difference,nums);
            freqMap[nums[i]]--;
        }
        return totalCount;
    }
};