class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // ans.push_back({});
        // for(auto num:nums)
        // {
        //    vector<vector<int>> newlist;
        //     for(auto x:ans)
        //     {
        //         x.push_back(num);
        //         newlist.push_back(x);
        //     }
        //     for(auto x : newlist)
        //         ans.push_back(x);
        // }

        backtracking(nums,0,{},ans);
        return ans;
    }
    // TC - O(N * 2^N) to generate all the subsets and copy them into the answer array
    // SC - O(N * 2^N)

    // Approach 2 
    void backtracking(vector<int> &nums,int index, vector<int> ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds);

        for(int i = index; i<nums.size();i++)
        {
            ds.push_back(nums[i]);
            backtracking(nums,i+1,ds,ans);
            ds.pop_back();
        }
    }
     // TC - O(N * 2^N) to generate all the subsets and copy them into the answer array
     // SC - O(N). we are taking ds to perfrom the task which will store at max N elements
};