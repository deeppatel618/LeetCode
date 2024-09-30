class Solution {
public:
    void combinationCalculator(int index, int sum, int target, vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            combinationCalculator(i,sum+nums[i],target,nums,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> resultTracker;
        vector<vector<int>> result;
        combinationCalculator(0,0,target,candidates,result,resultTracker);
        return result;
    }
};