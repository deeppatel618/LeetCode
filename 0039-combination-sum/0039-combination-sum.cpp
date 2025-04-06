class Solution {
public:
    // void combinationCalculator(int index, int sum, int target, vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp)
    // {
    //     if(sum > target) return;
    //     if(sum == target) {
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i = index; i < nums.size(); i++)
    //     {
    //         temp.push_back(nums[i]);
    //         combinationCalculator(i,sum+nums[i],target,nums,ans,temp);
    //         temp.pop_back();
    //     }
    // }

    void combinationCalculator(int index, int target, vector<int> curr, vector<int> candidates, vector<vector<int>> &ans)
    {
        if(target <= 0 || index == candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(curr);
            }
            return;
        }
        if(candidates[index] <= target)
        {
            curr.push_back(candidates[index]);
            combinationCalculator(index, target - candidates[index], curr,candidates,ans);
            curr.pop_back();
        }
        combinationCalculator(index+1, target, curr,candidates,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> resultTracker;
        vector<vector<int>> result;
        // combinationCalculator(0,0,target,candidates,result,resultTracker);
        combinationCalculator(0,target,{},candidates,result);
        return result;
    }
};