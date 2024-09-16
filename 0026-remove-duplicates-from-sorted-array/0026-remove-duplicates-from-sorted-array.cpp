class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int low=0,high=1;
        while(high!=nums.size())
        {
            if(nums[low]==nums[high])
            {
                nums[high] = -101;
                high++;
            }
            else
            {
                low = high;
                high++;
            } 
        }
        low = 0;
        high = 1; 
        while(high != nums.size()) {
            while(low < nums.size() && nums[low] != -101) {
                low++; 
            }
            while(high < nums.size() && nums[high] == -101) {
                high++;
            }
            // cout << low << "," << high << endl;
            if(low >= nums.size() || high >= nums.size()) {
                break;
            } else {
                if(low<high)
                {
                    nums[low] = nums[high];
                    nums[high] = -101;
                }
                else
                {
                    high++;
                }
            }
        }
        
        return low;
    }
};