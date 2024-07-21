class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakIndex=-1;
        for(int i = nums.size()-1 ; i>0 ;i--)
        {
            if(nums[i-1] < nums[i])
            {
                breakIndex=i;
                break;
            }
        }
        // cout<<breakIndex;
        if(breakIndex == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i = nums.size()-1 ; i>=breakIndex; i--)
        {
            if(nums[breakIndex-1] < nums[i] )
            {
                swap(nums[breakIndex-1], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+breakIndex, nums.end());
    }
};