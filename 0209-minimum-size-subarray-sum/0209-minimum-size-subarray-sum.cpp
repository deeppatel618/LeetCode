class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int size = INT_MAX;
        int left =0, right = 0;
        for(right = 0; right<nums.size();right++)
        {
            sum+=nums[right];
            if(sum>=target)
            {
                
                while(sum>=target)
                {
                    size = min(size,right-left+1);
                    sum-=nums[left];
                    left++;
                }
            }
        }
        return size == INT_MAX?0:size;
    }
};