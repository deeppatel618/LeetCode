class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<pair<int,pair<int,int>>> pq;
        
        vector<vector<int>> effort(rows,vector<int>(cols,1e9));
        effort[0][0] = 0;
        pq.push({0,{0,0}});

        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!pq.empty()){
            auto it = pq.top();
            int effortCost = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            for(auto dir:directions){
                int neighborRow = row + dir[0];
                int neighborCol = col + dir[1];

                if(neighborRow >=0 && neighborCol >= 0 && neighborRow<rows && neighborCol < cols){
                    int diffEffort = abs(heights[neighborRow][neighborCol] - heights[row][col]);
                    diffEffort = max(effortCost,diffEffort);
                    if(diffEffort < effort[neighborRow][neighborCol])
                    {
                        effort[neighborRow][neighborCol] = diffEffort;
                        pq.push({diffEffort,{neighborRow,neighborCol}});
                    }

                }
            }
        }
        return effort[rows - 1][cols - 1];
    }
};