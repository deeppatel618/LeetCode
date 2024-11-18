class Solution {
public:
    int lowerBound(vector<int> nums, int target)
    {
        int low = 0, high = nums.size()-1;
        int mid, first = -1;
        while(low<=high)
        {
            mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid -1;
        }
        return first;
    }
    int upperBound(vector<int> nums, int target)
    {
        int low = 0, high = nums.size()-1;
        int mid, last = -1;
        while(low<=high)
        {
            mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums,target);
        if(first == -1) return {-1,-1};
        return {first,upperBound(nums,target)};
    }
};