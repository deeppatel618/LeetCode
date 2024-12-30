class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int currMax = values[0] - 1;
        for(int i = 1; i<values.size(); i++)
        {
            int currRes = currMax + values[i];
            ans = max(ans, currRes);
            currMax = max(currMax - 1, values[i] - 1);

        }
        return ans;
    }
};