class Solution {
public:
    int helper(vector<int>& nums, int curr,int threshold)
    {
        int totalAns = 0;
        for(int i:nums)
        {
            totalAns += (i/curr) + (i%curr!=0);
            if(totalAns>threshold)
            {
                return 0;
            }
        }
        if(totalAns <= threshold)
            return 1;
        return 0;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            int isValid = helper(nums,mid,threshold);
            if(isValid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};