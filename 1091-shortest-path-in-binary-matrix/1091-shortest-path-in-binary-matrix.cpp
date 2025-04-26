class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1; // You change the soruce according to the requirment
        
        if(grid[0][0] == 0 && n == 1)
            return 1;
        else if(grid[0][0] == 0)
            q.push({1,{0,0}});
        else
            return -1;
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
        
        while(!q.empty()){
            auto it = q.front();
            int distance = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            
            for(auto dir:directions){
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if(newRow >=0 && newCol>=0 && newRow < n && newCol < n && grid[newRow][newCol] == 0 && distance + 1 < dist[newRow][newCol]){
                    dist[newRow][newCol] = distance + 1;
                    if(newRow == n-1 && newCol == n - 1) // reached destination
                        return dist[newRow][newCol]; 
                    q.push({distance+1,{newRow,newCol}});
            
                }
            }
        }
        return -1;

    }
};