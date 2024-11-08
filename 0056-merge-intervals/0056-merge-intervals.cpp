class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(auto it:intervals){
            if(ans.back()[1] >= it[0])
            {
                ans.back()[1] = max( ans.back()[1],it[1]);
            }
            else
            {
                ans.push_back(it);
            }
        }
        
        // ans.push_back(temp);
        return ans;
    }
};