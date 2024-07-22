class Solution {
public:
    void sorting(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(),intervals.end(),[](const std::vector<int>&a,   const std::vector<int>& b) 
        { return a[0] < b[0]; }
        );
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sorting(intervals);
        vector<vector<int>> ans;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i = 0; i < intervals.size()-1 ;i++)
        {
            if(end >= intervals[i+1][0])
            {
                end = end>intervals[i+1][1]? end:intervals[i+1][1];
            }
            else
            {
                vector<int> temp={start,end};
                start = intervals[i+1][0];
                end = intervals[i+1][1];
                ans.push_back(temp);
            }
        }
        vector<int> temp={start,end};
        ans.push_back(temp);
        return ans;
    }
};