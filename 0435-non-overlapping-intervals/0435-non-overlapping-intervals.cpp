class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals by their start time
        sort(intervals.begin(), intervals.end());
        
        int prev = 0; // Index of the previous interval
        int ans = 0;  // Count of intervals to remove
        
        for (int i = 1; i < intervals.size(); ++i) {
            // Check if the current interval overlaps with the previous one
            if (intervals[i][0] < intervals[prev][1]) {
                ++ans; // Increment the count of removed intervals
                // Keep the interval with the smaller end time
                if (intervals[i][1] < intervals[prev][1]) {
                    prev = i;
                }
            } else {
                prev = i; // Update the previous interval index
            }
        }
        return ans;
    }
};