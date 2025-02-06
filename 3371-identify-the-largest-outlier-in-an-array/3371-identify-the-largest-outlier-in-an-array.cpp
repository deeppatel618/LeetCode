class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int> mp;
        int totalSum = 0;

        for(int i:nums)
        {
            mp[i]++;
            totalSum+=i;
        }
        int outlier = INT_MIN;
        for(int i:nums)
        {   
            mp[i]--;
            totalSum-=i;

            if( totalSum%2 == 0 && mp[totalSum/2]>0)
            {
                outlier = max(outlier,i);
            }
            mp[i]++;
            totalSum+=i;
        }
        return outlier;
    }
};