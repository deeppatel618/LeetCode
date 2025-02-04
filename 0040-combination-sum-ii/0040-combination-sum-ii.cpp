class Solution {
public:
    void combinationSumTracker(int index,int sum,vector<vector<int>> &ans,vector<int>& nums, int target,vector<int>& temp)
    {
        if(sum > target || index > nums.size()) return;
        
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<nums.size();i++)
        {
            if(i>index && nums[i] == nums[i-1]) continue;
            if(nums[index]>target) break;
        temp.push_back(nums[i]);
        combinationSumTracker(i+1,sum+nums[i],ans,nums,target,temp);
        temp.pop_back();
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> resultTracker;
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        combinationSumTracker(0,0,result,candidates,target,resultTracker);
        return result;
    }
};