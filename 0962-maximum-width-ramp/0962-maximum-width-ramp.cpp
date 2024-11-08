class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> maxSoFar(nums.size());
        int maxEle=0;
        for(int i = nums.size()-1; i>=0;i--) 
        {
            maxEle = max(maxEle, nums[i]);
            maxSoFar[i] = maxEle;
        }
        int left = 0;
        int right =1;
        int ans = 0;
        while(right<nums.size())
        {
            while(left<right && nums[left] > maxSoFar[right])
            {
                left++;
            }
            ans = max(ans, right-left);
            right++;
        }
        return ans;
    }
};