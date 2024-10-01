class Solution {
public:
    void swap(int i, int j, vector<int> &nums)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void permutationCalculator(int index, vector<int> &nums,vector<vector<int>> &ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size();i++)
        {
            swap(index,i,nums);
            permutationCalculator(index+1,nums,ans);
            swap(index,i,nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutationCalculator(0,nums,ans);
        return ans;
    }
};