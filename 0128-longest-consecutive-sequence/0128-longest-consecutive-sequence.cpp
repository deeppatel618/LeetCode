class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        unordered_set<int> tracker;
        for(int i = 0 ; i<nums.size();i++)
        {
            tracker.insert(nums[i]);
        }
        int counter = 0;
        int ans=0;
        for(auto i : tracker)
        {   
            if(tracker.find(i-1) == tracker.end())
            {
                counter=1;
                while(tracker.find(i+counter)!= tracker.end()) counter++;
            }
            ans = max(ans,counter);
            counter = 1;
        }   
        return ans;
    }
};