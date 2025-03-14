class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(maxReach<i) return false;
            maxReach = max(maxReach, nums[i]+i);
            if(maxReach>=nums.size()) return true;
        }
        return true;
    }
};