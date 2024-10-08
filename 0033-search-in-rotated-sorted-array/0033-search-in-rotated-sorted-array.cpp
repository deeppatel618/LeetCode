class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        if (nums[mid] == target)
            return mid;
        if (nums[low] <=  nums[mid]) // part 1 is sorted.
        {
            // cout<<low<<","<<mid<<","<<high<<endl;
            if (nums[low] <= target && nums[mid] > target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
            mid = (low + high) / 2;
        }
        else // part 2 is sorted
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid+1;
            else
                high = mid-1;
            mid = (low + high) / 2;
        }
    }
    return -1;
    }
};