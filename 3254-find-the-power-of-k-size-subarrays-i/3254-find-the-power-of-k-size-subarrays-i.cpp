class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if( k == 1) 
            return nums; // As k 1 will make all the number consecutive for that frame.
        
        int consecutive=1;
        vector<int> ans(nums.size()- k+1,-1);
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] + 1 == nums[i+1])
            {
                consecutive+=1;
            }
            else
            {
                consecutive = 1;
            }
            if(consecutive >=k)
            {
                ans[i-k+2] = nums[i+1];
            }
        }
        return ans;
    }
};