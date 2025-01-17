class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp(nums.size());
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i<nums.size();i++)
        {
            sum+=nums[i];
            int key = sum -k;
            if(mp.find(key) !=mp.end())
            {
                ans+=mp.find(key)->second;
            }
            mp[sum]++;
        }
        return ans;

    }
};