class Solution {
public:
    // Pick and not pick can work here but we need extra data structure to keep track of which element is picked up. 
    // To avoid extra space. We can use swap to give chance to all the elements to be at a certain position.
    // For [1,2,3] - > We can have [1,2,3], [2,1,3],[3,2,1] and so on.
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
    //what you should say in an interview: O(n⋅n!)
};