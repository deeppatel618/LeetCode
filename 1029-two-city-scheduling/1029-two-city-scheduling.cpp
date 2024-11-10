class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0;
        sort(costs.begin(),costs.end(),[](const vector<int> &a, const vector<int> &b){
            return a[0]-a[1]<b[0]-b[1];
        });
        for(int i = 0;i<costs.size();i++)
        {
            if(i<(costs.size()/2))
            {
                sum+=costs[i][0];
            }
            else
            {
                sum+=costs[i][1];
            }
        }
        return sum;
    }
};