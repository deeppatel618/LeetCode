class Solution {
public:
    int BinarySearch(vector<int> &nums,int low, int high, int element)
    {
        int mid;
        while(low<=high)
        {
            mid = low + (high - low)/2;

            if(nums[mid] >= element)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            int low = BinarySearch(nums, i+1,nums.size()-1, lower - nums[i]);
            int high = BinarySearch(nums, i+1,nums.size()-1, upper-nums[i]+1);
            ans += 1LL*(high - low);
        }
        return ans;
    }
};