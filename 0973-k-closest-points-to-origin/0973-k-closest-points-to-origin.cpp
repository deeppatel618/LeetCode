class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>> pq;
        for(int i = 0; i<points.size(); i++)
        {
            float dist = euclideanDistance(points[i][0],points[i][1]);
            pq.push({dist,i});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
    float euclideanDistance(int a, int b){
        return a*a +b*b;
    }
};