class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1; // You change the soruce according to the requirment
        if(grid[0][0] == 0)
            q.push({1,{0,0}});
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int distance = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            for(auto dir:directions){
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if(newRow >=0 && newCol>=0 && newRow < n && newCol < n && grid[newRow][newCol] == 0 && distance + 1 < dist[newRow][newCol]){
                    dist[newRow][newCol] = distance + 1;
                    if(newRow == n-1 && newCol == n - 1) // reached destination
                        return dist[newRow][newCol]; 
                    q.push({distance+1,{newRow,newCol}});
                    // cout<<"pushed - "<< newRow<<"-"<<newCol<<endl;
                }
            }
        }
        return dist[n-1][n-1] == 1e9? -1:1;

    }
};